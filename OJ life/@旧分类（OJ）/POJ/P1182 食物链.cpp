//#include <iostream>
//using namespace std;
#include <cstdio>

const int MAX=50010;
int father[MAX],offset[MAX];
int n,k,d,x,y,i,count=0;

int FindSet(int x);
void Union(int d,int x,int y);
int main()
{
//	ios::sync_with_stdio(false);
//	cin>>n>>k;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;++i) father[i]=i;
	for (i=1;i<=k;++i){
//		cin>>d>>x>>y;
		scanf("%d%d%d",&d,&x,&y);
		if ((x>n) || (y>n) || (d == 2)&&(x == y))
			count++;
		else
			if ((FindSet(x) != FindSet(y)))
				Union(d-1,x,y);
			else
				if ((offset[x] - offset[y] + 3)%3 != (d-1))
					count++;
	}
//	cout<<count<<endl;
	printf("%d\n",count);
	return 0;
}

int FindSet(int x){
	if (x != father[x]){
		int temp=father[x];
		father[x]=FindSet(father[x]);
		offset[x]=(offset[x]+offset[temp]+3)%3;
	}
	return father[x];
}

void Union(int d,int x,int y){
	int fx = FindSet(x);
	int fy = FindSet(y);
	father[fx]=fy;
	offset[fx]=(offset[y]-offset[x]+3+d)%3;
	return;
}
