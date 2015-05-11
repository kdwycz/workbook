#include <iostream>
#include <cstring>
using namespace std;
const int M=105;

bool map[M][M],flag;
int ru[M],chu[M],kk[M];
int a,b,n=0;

void dfs(int i){
	kk[i]=0;
	for (int j=1;j<M;++j)
		if (map[i][j])
			if (kk[j]==0) 
				flag=false;
			else 
				dfs(j);
	return;
}

int main()
{
	while (cin>>a>>b && a!=-1){
		memset(map,0,sizeof(map));
		memset(ru,0,sizeof(ru));
		memset(chu,0,sizeof(chu));
		memset(kk,0,sizeof(kk));
		flag=true;
		
		if (a!=0 && b!=0){
			do{
				if (map[a][b]) flag=false;
				kk[a]=kk[b]=1;
				map[a][b]=1;
				ru[b]++; chu[a]++;
			}while (cin>>a>>b && a && b);
			
			int k=0;
			for (int i=1;i<M;++i){
				if (kk[i] && !ru[i])
					if (!k)
						k=i;
					else
						flag=false;
				if (ru[i]>1) flag=false;
			}
			if (!k) flag=false;
			if (flag) dfs(k);
		}
		if (flag)
			cout<<"Case "<<++n<<" is a tree.\n";
		else
			cout<<"Case "<<++n<<" is not a tree.\n";
	}
	return 0;
}

/*
#include <iostream>
using namespace std;
const int M=105;

int set[M],flag,a,b,n=0;

void init(){
	for (int i=0;i<M;++i)
		set[i]=i;
}

int FindSet(int x){
	if (x!=set[x])
		x=FindSet(set[x]);
	return set[x];
}

void Union(int x,int y){
	set[y]=set[x];
}

int main()
{
	while (cin>>a>>b && a!=-1){
		flag=true; init();
		if (a==0) 
			flag=true;
		else
			do{
				int fa=FindSet(a);
				int fb=FindSet(b);
				if (fa==fb) flag=false;
				if (fb!=b) flag=false;
				Union(a,b);
			}while (cin>>a>>b && a && b);
		a=0;
		for (int i=0;i<M;++i){
			int fi=FindSet(i);
			if (fi!=i)
				if (!a) 
					a=fi;
				else if (a!=fi)
					flag=false;
		}
		if (flag)
			cout<<"Case "<<++n<<" is a tree.\n";
		else
			cout<<"Case "<<++n<<" is not a tree.\n";
	}
	return 0;
}
*/
