#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)

int main()
{
	srand((int)time(0));
	for(int x=0;x<10;x++)
		printf("%d\n",random(100));
	return 0;
}


#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
//	ifstream fin("aa.txt");
	ofstream fout("bb.txt");
	int i;
	srand((int)time(0));
	for (i=0; i<9999; i++) {
		fout<<rand()%1000<<' ';
 	}
 	return 0;
}
