#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	cout<<"n e"<<endl<<"- -----------"<<endl<<"0 1"<<endl
 		<<"1 2"<<endl<<"2 2.5"<<endl;;
	double a=2.5; int ii=2;
	cout.precision(9);
	for(int i=3;i<10;++i){
		ii*=i;
		a+=1.0/ii;
		cout<<i<<' '<<fixed<<a<<endl;
	}
	return 0;
}