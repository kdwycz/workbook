#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int dir[8][2]={-1,-2,1,-2,-2,-1,2,-1,-2,1,2,1,-1,2,1,2};
// -1, 1,-2, 2,-2, 2,-1, 1  本题最大难点 
// -2,-2,-1,-1, 1, 1, 2, 2  字典序 

string s;
int graph[10][10],out[100][2],n,m,a,b,flag,i;

void dfs(int,int,int);
void print();

int main()
{
	cin>>n;
	for (i=0;i<n;++i){
		cin>>a>>b;
		m=a*b; flag=0;
		memset(graph,0,sizeof(graph));
		memset(out,0,sizeof(out));
		graph[1][1]=1; out[1][0]=1; out[1][1]=1; 
		dfs(1,1,1);
		if (!flag){
			cout<<"Scenario #"<<i+1<<":\n";
			cout<<"impossible\n\n";
		} 
	}
	return 0;
}

void print(){
	flag=1;
	int j=1;
	char a;
	cout<<"Scenario #"<<i+1<<":\n";
	while (out[j][0]!=0){
		a='A'+out[j][1]-1;
		cout<<a<<out[j][0]; 
		j++;
	}
	cout<<endl<<endl;
	return;
}

void dfs(int ii,int ix,int iy){
	if (flag) return;
	if (ii==m) print();
	else{
		for (int i=0;i<=7;++i)
			if (ix+dir[i][0]>0 && ix+dir[i][0]<=a && iy+dir[i][1]>0 && 
			iy+dir[i][1]<=b && !graph[ix+dir[i][0]][iy+dir[i][1]]){
				graph[ix+dir[i][0]][iy+dir[i][1]]=1;
				out[ii+1][0]=ix+dir[i][0];
				out[ii+1][1]=iy+dir[i][1];
				dfs(ii+1,ix+dir[i][0],iy+dir[i][1]);
				graph[ix+dir[i][0]][iy+dir[i][1]]=0;
				out[ii+1][0]=0;
				out[ii+1][1]=0;
			}
	}
	return; 
}
