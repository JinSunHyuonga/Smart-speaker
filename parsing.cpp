#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <string>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY   0x12345 
#define MEMORY_SIZE 200

#define PARSING "0"
#define YOUTUBE "1"
#define WEATHER "2"
#define WEATHERg "g"
#define WEATHERc "c"
#define WEATHERj "j"
#define WEATHERG "G"
#define CALENDAR "3"

using namespace std;

int main (int argc, char *const argv[])
{
    int shmid, whileint=0;
	char* Function;
	char* String;
	char* Sbuffer;
	
	string PyName = "마카오";

	string Youtube0 = "틀어줘";
	string Youtube1 = "노래";
	string Youtube2 = "음악";
	string Youtube3 = "들려줘";
	string Youtube4 = "유튜브";
	string Youtubef1 = "다음";
	string Youtubef2 = "이전";

	string Weather0 = "날씨";
	string Weatherg = "경기";
	string Weatherc = "충청";
	string Weatherj = "전라";
	string WeatherG = "경상";

	string Stop0 = "멈춰";
	string Stop1 = "그만";
	string Stop2 = "정지";

	string CalendarK = "일정";
	string CalendarE = "캘린더";

    shmid = shmget((key_t)SHM_KEY, 0, NULL);
    if(shmid == -1) {
        perror("parsing shmget( )");
        return -1;
    }

    Function = (char*)shmat(shmid, NULL, 0);
    if(Function == (void *)-1) {
        perror("parsing shmat( )");
        return -1;
    }

	String = Function + 1;
	std::string Buffer(String);

	//pi serch
	if( (Buffer.find(PyName) != string::npos) )
	{
		//YOUTUBE	strcpy(Function,YOUTUBE);
		while(1)	{
			if( (Buffer.find(Youtube0) != string::npos) )	{
				strcpy(Function,YOUTUBE);
				break;
			}		
			if( (Buffer.find(Youtube1) != string::npos) )   {
    	        strcpy(Function,YOUTUBE);
                break;
        	}
			if( (Buffer.find(Youtube2) != string::npos) )   {
    	        strcpy(Function,YOUTUBE);
                break;
        	}
			if( (Buffer.find(Youtube3) != string::npos) )   {
    	        strcpy(Function,YOUTUBE);
                break;
        	}
			if( (Buffer.find(Youtube4) != string::npos) )   {
    	        strcpy(Function,YOUTUBE);
                break;
        	}
		break;
		}
		//WEATHER	strcpy(Function,YOUTUBE);
		if( (Buffer.find(Weather0) != string::npos) )   {
            strcpy(Function,WEATHER);
			if( (Buffer.find(Weatherg) != string::npos) )
            strcpy(Function,WEATHERg);
			if( (Buffer.find(Weatherc) != string::npos) )   
            strcpy(Function,WEATHERc);
			if( (Buffer.find(Weatherj) != string::npos) )   
            strcpy(Function,WEATHERj);
			if( (Buffer.find(WeatherG) != string::npos) )   
            strcpy(Function,WEATHERG);
        }
		
	    if( (Buffer.find(CalendarK) != string::npos) )   {
    	    strcpy(Function,CALENDAR);
	    }
	    if( (Buffer.find(CalendarE) != string::npos) ){
	        strcpy(Function,CALENDAR);
	    }

	}
	else	{
		cout << "not found pi" << endl;
		strcpy(Function,"9");
	}

	Sbuffer = strdup(Buffer.c_str());
	strcpy(String,Sbuffer);
	cout << "parsing Function : " << Function[0] << endl;
	cout << "parsing String : " << String << endl;
	cout << "parsing end " << endl;
    return 0;
}
