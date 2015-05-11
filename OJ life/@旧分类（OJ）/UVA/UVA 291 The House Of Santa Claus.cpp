#include <iostream>
using namespace std;

int map[6][6]={	{0,0,0,0,0,0},
				{0,0,1,1,0,1},
				{0,1,0,1,0,1},
				{0,1,1,0,1,1},
				{0,0,0,1,0,1},
				{0,1,1,1,1,0}};

void dfs(int x,int k,string s){
	s+=char('0'+x);
	if (k==8){
		cout<<s<<endl;
		return;
	} 
	for (int i=1;i<=5;++i)
		if (map[x][i]){
			map[x][i]=0;
			map[i][x]=0;
			dfs(i,k+1,s);
			map[x][i]=1;
			map[i][x]=1;
		}
	return;
}
int main()
{
	dfs(1,0,""); 
	return 0;
}
