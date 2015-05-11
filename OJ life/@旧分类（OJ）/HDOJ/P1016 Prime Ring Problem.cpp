#include <iostream>
using namespace std;

int a[21]={0},s[21]={0},b[40]={0},aa,ii=1;
void dfs(int);
int main(int argc, char *argv[])
{
	b[2]=1;  b[3]=1;  b[5]=1;  b[7]=1;
	b[11]=1; b[13]=1; b[17]=1; b[19]=1;
	b[23]=1; b[29]=1; b[31]=1; b[37]=1; 	
	while (cin>>aa){
		memset(a,0,sizeof(a));
		cout<<"Case "<<ii<<":\n"; 
		a[1]=1; s[1]=1;
		dfs(1); ii++;
		cout<<endl; 
	}
	return 0;
}

void dfs(int i){
	if((i==aa)&&(b[s[i]+s[1]])) 
		for(int j=1;j<=aa;++j){
			cout<<s[j];
			if (j<aa) cout<<' ';
			else cout<<endl;
		}
	else
		for(int j=2;j<=aa;++j)
			if ((!a[j])&&(b[j+s[i]])){
				a[j]=1; s[i+1]=j;
				dfs(i+1);
				a[j]=0; s[i+1]=0; //s[j]=0; ¿ÉÒÔÈ¥µô 
			}
}