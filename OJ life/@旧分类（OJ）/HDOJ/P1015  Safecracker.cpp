#include <iostream>
using namespace std;
 
int pow(int x,int n){
	int m=x;
	for(int i=1;i<n;++i) m*=x;
	return m; 
}

int main(int argc, char *argv[])
{
	string s;
	int a,ii,i,j,k,l,m,flag;
	while ((cin>>a>>s)&&(s!="END")){
		ii=s.length(); flag=1;
		for(i=0;i<ii-1;++i)
	 		for(j=i+1;j<ii;++j)
			 	if(s[i]<s[j]){
	 				s[i]=s[i]^s[j];
					s[j]=s[i]^s[j];
					s[i]=s[i]^s[j];
	 			} 
		for(i=0;i<ii;++i)
		for(j=0;j<ii;++j)
		for(k=0;k<ii;++k)
		for(l=0;l<ii;++l)	
		for(m=0;m<ii;++m)
			if ((flag)&&(j!=i)&&(k!=j)&&(k!=i)&&(l!=k)&&(l!=j)&&(l!=i)&&(m!=l)&&(m!=k)&&(m!=j)&&(m!=i)&&
			   ((s[i]-64)-pow(s[j]-64,2)+pow(s[k]-64,3)-pow(s[l]-64,4)+pow(s[m]-64,5)==a)){
				cout<<s[i]<<s[j]<<s[k]<<s[l]<<s[m]<<endl;
				flag=0;
			}
		if (flag) cout<<"no solution"<<endl;
	}
	return 0;
}
