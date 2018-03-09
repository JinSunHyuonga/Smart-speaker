#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>

#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY   0x12345 

using namespace std;

string google_string;

struct SharedMemory {
    string Stt_String;
    string Stt_Function;
    string Function_string;
};

int main (int argc, char *const argv[])
{
    // make SHM
    SharedMemory Share_String = {"p1","p2","p3"};
    cout << "parsing shme1 : " << Share_String.Stt_String << endl;
    cout << "parsing shme2 : " << Share_String.Stt_Function << endl;
    cout << "parsing shme3 : " << Share_String.Function_string << endl;
    int shmid;
    struct SharedMemory *Point_SharedMemory;
    void *shmmem = (void *)0;

    shmid = shmget((key_t)SHM_KEY, sizeof(char)*100, 0666 | IPC_CREAT);
    if(shmid == -1) {
        perror("shmget( )");
        return -1;
    }

    shmmem = shmat(shmid, (void *)0, 0);
    if(shmmem == (void *)-1) {
        perror("shmat( )");
        return -1;
    }
    Point_SharedMemory = (struct SharedMemory *)shmmem;
	cout << "parsing shme1-1 : " << Point_SharedMemory->Stt_String << endl;
    cout << "parsing shme1-2 : " << Point_SharedMemory->Stt_Function << endl;
    cout << "parsing shme1-3 : " << Point_SharedMemory->Function_string << endl;
		
	memcpy(&Share_String,Point_SharedMemory,sizeof(SharedMemory));

	cout << "piont_SharedMemoty" << Point_SharedMemory << endl;

	cout << "parsing shme2-1 : " << Share_String.Stt_String << endl;
    cout << "parsing shme2-2 : " << Share_String.Stt_Function << endl;
    cout << "parsing shme2-3 : " << Share_String.Function_string << endl;

	//input SHM value
//    Share_String.Stt_String = google_string;
//    cout << "shme1 test : " << Share_String.Stt_String << endl;
    memcpy(Point_SharedMemory,&Share_String,sizeof(SharedMemory));

    return 0;
}
