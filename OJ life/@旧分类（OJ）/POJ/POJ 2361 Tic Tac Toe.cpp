#include <iostream>
using namespace std;
int main()
{
	string a[4];
	int f,n,wo,wx,no,nx,i,j;
	cin>>n;
	while (n--){
		wo=wx=no=nx=0; f=1;
		for (i=0;i<3;++i)
			cin>>a[i];
		for (i=0;i<3;++i)
			for (j=0;j<3;++j){
				if (a[i][j]=='O')
					no++;
				if (a[i][j]=='X')
					nx++;
			}
				
	
		if (a[0][0]==a[0][1] && a[0][1]==a[0][2]){
			if (a[0][1]=='O') wo=1;
			if (a[0][1]=='X') wx=1;
		}
		if (a[1][0]==a[1][1] && a[1][1]==a[1][2]){
			if (a[1][1]=='O') wo=1;
			if (a[1][1]=='X') wx=1;
		}
		if (a[2][0]==a[2][1] && a[2][1]==a[2][2]){
			if (a[2][1]=='O') wo=1;
			if (a[2][1]=='X') wx=1;
		}
		if (a[0][0]==a[1][0] && a[1][0]==a[2][0]){
			if (a[1][0]=='O') wo=1;
			if (a[1][0]=='X') wx=1;
		}
		if (a[0][1]==a[1][1] && a[1][1]==a[2][1]){
			if (a[1][1]=='O') wo=1;
			if (a[1][1]=='X') wx=1;
		}
		if (a[0][2]==a[1][2] && a[1][2]==a[2][2]){
			if (a[1][2]=='O') wo=1;
			if (a[1][2]=='X') wx=1;
		}
		if (a[0][0]==a[1][1] && a[1][1]==a[2][2]){
			if (a[1][1]=='O') wo=1;
			if (a[1][1]=='X') wx=1;
		}
		if (a[0][2]==a[1][1] && a[1][1]==a[2][0]){
			if (a[1][1]=='O') wo=1;
			if (a[1][1]=='X') wx=1;
		}
		
		if (no>nx) f=0;
		if (nx-no>=2) f=0;
		if (wo && wx) f=0;
		if (wo && no!=nx) f=0;
		if (wx && no==nx) f=0;
		
		if (f)
			cout<<"yes\n";
		else
			cout<<"no\n";
		
	}
	return 0;
} 
