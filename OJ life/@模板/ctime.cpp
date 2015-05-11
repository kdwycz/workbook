#include <iostream>
#include <ctime>
using namespace std;
int main(int argc, char *argv[])
{
	cout<<"Enter the delay time, in seconds:";
	float secs;
	cin>>secs;
	clock_t delay =secs*CLOCKS_PER_SEC;
	cout<<"starting\a\n";
	clock_t start =clock();
	while (clock()-start<delay);
	cout<<"done\n";
	return 0;
}