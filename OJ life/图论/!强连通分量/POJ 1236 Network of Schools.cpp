#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
const int M = N * N;

int head[N]={0},link[M]={0},next[M]={0};
int stap[N]={0},dfn[N]={0},low[N],belong[N]={0};
bool stack[N]={0},ru[N]={0},chu[N]={0};
int n,m,stop=0,bcnt=0,dindex=0,rr=0,cc=0;

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
		}while (k!=i);
	}
}


int main()
{
	cin>>n; int a; m=0;
	for (int i=1;i<=n;++i)
		while (cin>>a && a){
			++m;
			link[m]=a;
			next[m]=head[i];
			head[i]=m;
		}
	
	for (int i=1;i<=n;++i)
		if (!dfn[i]) tarjan(i);
	
	for (int i=1;i<=n;++i)
		for (int j=head[i];j;j=next[j])
			if (belong[i]!=belong[link[j]]){
				chu[belong[i]]=1; ru[belong[link[j]]]=1;
			}
	for (int i=1;i<=bcnt;++i){
		if (!ru[i]) rr++;
		if (!chu[i]) cc++;
	}
	if (bcnt==1)
		cout<<"1\n0\n";
	else
		cout<<rr<<endl<<max(rr,cc)<<endl;
	
	return 0;
} 
