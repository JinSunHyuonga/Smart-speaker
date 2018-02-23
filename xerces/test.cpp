#include <iostream>
#include <fstream>
using namespace std;
 
int main( int argc, char** argv )
{
 system( "ls > aaa.txt" );
 char tmp[256];
 ifstream fin( aaa.txt );
 while( fin >> tmp )
 {
 cout << tmp << endl;
 }
 fin.close();
 
 return 0;
}
