#include <iostream>
#include <thread>
#include <Python.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>

#include <sys/ipc.h> 
#include <sys/shm.h> 

#define SHM_KEY   0x12345 

using namespace std;

string google_string;
int mutex = 0;
int countdown_recoding = 0;
int Interrup = 0;

void InteruptFunc()	{
	while(1)	{
		cin >> Interrup;
		if (Interrup == 1)
			google_string = "종료";
			break;
	}
}
void CountFunc()	{
	for(;countdown_recoding != 0;){
		cout << countdown_recoding << endl;
		countdown_recoding -= 1;
		sleep(1);
	}
	cout << "counting thread end" << endl;
}

int SttFunc()	{
	std::cout << "start stt" << std::endl;

	PyObject *pName, *pModule;	//for load python script
	PyObject *pgoogle_stt;	//for python functions
	PyObject *g_pArgs, *g_pValue;	//for get/set python function parameters
	Py_Initialize();
	//start set path
	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyString_FromString("."));
	
	//get python script
	pName = PyString_FromString("stt");
	cout << "stt init" << endl;
	pModule = PyImport_Import(pName);
		cout << pModule << endl;
	Py_DECREF(pName);
	
	if (pModule != NULL)
	{
		//module load
		pgoogle_stt = PyObject_GetAttrString(pModule, "google_stt");	
		//module load error check
        if ( !(pgoogle_stt && PyCallable_Check(pgoogle_stt)) )
        {
            if (PyErr_Occurred()) PyErr_Print();
            std::cout << "Cannot find function 'google_stt'" << std::endl;
        }
        g_pArgs = PyTuple_New(100); //make parameter list
		g_pArgs = PyObject_CallObject(pgoogle_stt, NULL);
		cout << "before stt API" << endl;
		//google stt API
		google_string = PyString_AsString(g_pArgs);
		cout << "after stt API" << endl;
	}
	else
	{
		PyErr_Print();
		std::cout << "Failed to load 'pModules'" << std::endl;
	}
	Py_Finalize();
	return 0;
}

int SttFunc_repeat()    {
    while(1)    {
		if (countdown_recoding !=0)
            sleep(5);
        if (mutex == 0) {
            cout << "main record start" << endl;
            system("./record_to_wav_level_check");
			//start google stt func
	        SttFunc();
			system("rm input.wav");
            std::cout << "google_stt : " << google_string << std::endl;
            mutex = 1;
        }
        if (mutex == 1) {
        countdown_recoding = 5;
        cout << "counting thread start" << endl;
        thread t_countdonw_recoding(&CountFunc);
        t_countdonw_recoding.detach();
        }

		if (google_string == "종료")
            break;
    }
    return 0;
}

struct SharedMemory {
	string Stt_String;
	string Stt_Function;
	string Function_string;
};

int main (int argc, char *const argv[])
{
	//interupt
	thread t_interupt(&InteruptFunc);
	// start Stt repeat
	thread t_stt(&SttFunc_repeat);
	// make SHM
	SharedMemory Share_String = {"1","2","3"};
	cout << "shme1 : " << Share_String.Stt_String << endl;
	cout << "shme2 : " << Share_String.Stt_Function << endl;
	cout << "shme3 : " << Share_String.Function_string << endl;
	int shmid;
	struct SharedMemory *Point_SharedMemory;
	void *shmmem = (void *)0;

	shmid = shmget((key_t)SHM_KEY, sizeof(char)*100, 0666 |IPC_CREAT); 
	if(shmid == -1) {
		perror("shmget( )");
		return -1; 
	}   

	shmmem = shmat(shmid, (void *)0, 0666 | IPC_CREAT);
	if(shmmem == (void *)-1) {
		perror("shmat( )");
		return -1; 
	}   
	Point_SharedMemory = (struct SharedMemory *)shmmem;
	cout << "main point_)SharedMemoty" << Point_SharedMemory <<endl;
	//Text Parsing repeat
	while(1)	{
		if (google_string == "종료")
			break;
		if (mutex == 1)	{
			//input SHM value
			Share_String.Stt_String = google_string;
			cout << "shme1 test : " << Share_String.Stt_String << endl;
			memcpy(Point_SharedMemory,&Share_String,sizeof(SharedMemory));
			//parsing
			system("./parsing");
			cout << google_string <<endl;
			google_string = "";
			//start API
//			cout << "update shme1 : " << Point_SharedMemory.Stt_String << endl;
//			cout << "uptade shme2 : " << Point_SharedMemory.Stt_Function << endl;
//			cout << "uptade shme3 : " << Point_SharedMemory.Function_string << endl;
			//shm read
			cout << "clear" <<endl;			
			mutex = 0;
		}
	}

	t_interupt.join();
	t_stt.join();
	return 0;
}
