#include <iostream>
#include <Python.h>
using namespace std;


int main (int argc, char *const argv[])
{
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

	pModule = PyImport_Import(pName);
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
            return 1;
        }
		std::cout << "start stt" << std::endl;			
		system("./record_to_wav_level_check");
		string google_string;
		//pgoogle_stt : function without input/output
        g_pArgs = PyTuple_New(100); //make parameter list
		g_pArgs = PyObject_CallObject(pgoogle_stt, NULL);
		google_string = PyString_AsString(g_pArgs);
		std::cout << "google_stt : " << google_string << std::endl;
	}
	else
	{
		PyErr_Print();
		std::cout << "Failed to load 'hello'" << std::endl;
		return 1;
	}
	
	Py_Finalize();
	return 0;
}
