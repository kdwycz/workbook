//一个略靠谱的hash判重 
#include <iostream>
using namespace std;

const int dx[4]={ 1,-1, 0, 0};
const int dy[4]={ 0, 0, 1,-1};
const int MAX=362280,MAXH=999983;

struct node{
	int a[3][3],x,y,step;
}queue[MAX]={0},end,temp;

int t,i,j,k,fa,so; string s;
int hash[MAXH]={0};

bool equal(node x,node y){
	for (int i=0;i<3;i++)
		for (int j=0;j<3;++j)
			if (x.a[i][j]!=y.a[i][j]) 
				return false;
	return true;
} 

int Hash(node x){
	int k=1;
	t=0;
	for (int i=0;i<3;++i)
		for (int j=0;j<3;++j){
			t+=x.a[i][j]*k;
			k*=10;
		}
	k=t%MAXH;
	while (hash[k] && hash[k]!=t) k=(k+1)%MAXH;
	return k; 
}

int main()
{
	cin>>s;
	for (i=0;i<3;++i)
		for (j=0;j<3;++j)
			if (s[i*3+j]>48)
				queue[0].a[i][j]=s[i*3+j]-48;
			else{
				queue[0].x=i; queue[0].y=j;
				queue[0].a[i][j]=0;
			}
	queue[0].step=0;
	cin>>s;
	for (i=0;i<3;++i)
		for (j=0;j<3;++j)
			if (s[i*3+j]>48)
				end.a[i][j]=s[i*3+j]-48;
			else{
				end.x=i; end.y=j;
				end.a[i][j]=0;
			}
	fa=so=0;
	while (fa<=so && so<MAX){
		for (i=0;i<4;++i)
			if (queue[fa].x+dx[i]>=0 && queue[fa].x+dx[i]<3 && queue[fa].y+dy[i]>=0 && queue[fa].y+dy[i]<3){
				temp=queue[fa];
				swap(temp.a[temp.x][temp.y],temp.a[temp.x+dx[i]][temp.y+dy[i]]);
				temp.x+=dx[i]; temp.y+=dy[i]; temp.step++;
				if (equal(temp,end)){
					cout<<temp.step<<endl;
					return 0;
				}
				int flag=Hash(temp);
				if (hash[flag]==0){
					hash[flag]=t;
					queue[++so]=temp;
				}
			}
		++fa;
	}
	cout<<"-1\n";
	return 0;
}

