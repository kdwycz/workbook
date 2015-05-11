#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int y;
	double i=1,n=0;
	while (cin>>y && y){
		y=4<<(y-1960)/10;
		while (n<y)
			n+=log(++i)/log(2); 
		cout<<(int)i-1<<endl;			
	}
	return 0;
}
