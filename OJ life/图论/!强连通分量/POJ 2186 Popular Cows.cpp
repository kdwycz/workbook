#include <iostream>
using namespace std;
const int N=10010;
const int M=50010;

int head[N]={0};
int link[M]={0},next[M]={0};
int stap[N]={0},dfn[N]={0},low[N],belong[N],ans[N]={0}; bool stack[N]={0},ru[N]={0};
int n,m;
int stop=0,bcnt=0,dindex=0;

void tarjan(int i){
	int k;
	dfn[i]=low[i]=++dindex;
	stack[i]=true;
	stap[++stop]=i;
	for (int j=head[i];j;j=next[j]){
		k=link[j];
		if (!dfn[k]){
			tarjan(k);
			low[i]=low[i]>low[k]?low[k]:low[i];
		}
		else if (stack[k] && dfn[k]<low[i])
			low[i]=dfn[k];
	}
	if (dfn[i]==low[i]){
		bcnt++;
		do{
			k=stap[stop--];
			stack[k]=false;
			belong[k]=bcnt;
			++ans[bcnt];
		}while (k!=i);
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		int a,b;
		cin>>a>>b;
		link[i]=b;
		next[i]=head[a];
		head[a]=i;
	}
	for (int i=1;i<=n;++i)
		if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;++i)
		for (int j=head[i];j;j=next[j])
			if (belong[i]!=belong[link[j]]) ru[belong[i]]=true;
	int aa=0;
	for (int i=1;i<=bcnt;++i)
		if (!ru[i])
			if (aa==0)
				aa=i;
			else
				aa=-1;
	if (!aa) aa=-1;
	
	cout<<ans[aa]<<endl;
	
	return 0; 
}
