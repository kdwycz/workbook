#include <iostream>
#include <cstring>
using namespace std;

struct node{
	int k,step;
}queue[10000],temp;

bool b[10000]={0};
int hash[10000];
int i,j,k,n,end,fa,so;

int change(int x,int n,int k);
int bfs();

int main()
{
	for (i=2;i<5000;++i)
		if (!b[i]){
			j=i; k=j+j;
			while (k<10000){
				b[k]=1; k+=j;
			}
		}
	cin>>n;
	while (n--)
		cout<<bfs()<<endl;
	return 0;
}
int change(int x,int n,int k){
	int i,j,t2,t3,t1=1;
	if (n==1 && k==0) return 0;
	for (i=4;i>=n;--i) t1*=10;
	t3=x%(t1/10);
	t2=x/t1;
	t2=t2*10+k;
	t2=t2*t1/10+t3;
	if (!b[t2] && !hash[t2]) return t2;
	return 0;
}

int bfs(){
	int i,j,k,fa=0,so=0;
	memset(hash,0,sizeof(hash));
	cin>>queue[fa].k>>end;
	hash[queue[fa].k]=1;
	queue[fa].step=0;
	while (fa<=so){
		for (i=1;i<=4;++i)
			for (j=0;j<=9;++j){
				k=change(queue[fa].k,i,j);
				if (k){
					hash[k]=1;
					if (k==end)
						return queue[fa].step+1;
					queue[++so].k=k;
					queue[so].step=queue[fa].step+1;
				}
			}
		++fa;
	}
	return 0;
}
