#include<iostream>
using namespace std;
int main(){
    int i,t,n,k,m;
    while(cin>>n){
        m=0; t=0;
        for(i=0;i<n;i++){
			cin>>k;
			if(k>=2) t++;
			m^=k;
        }
		if((m==0&&t>=2)||(m!=0&&t==0)) 
			cout<<"No\n";
		else 
			cout<<"Yes\n";
     }
     return 0;
 }
