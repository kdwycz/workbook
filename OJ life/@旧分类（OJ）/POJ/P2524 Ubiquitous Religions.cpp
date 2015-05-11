#include <cstdio>

int set[50010],score[50010];
int m,n,x,y,i,no,ss;

int FindSet(int x);
void Union(int x,int y);
int main()
{
	no=0;
	while (scanf("%d%d",&n,&m) && n!=0){
		no++; ss=0;
		for (i=1;i<=n;++i){
			set[i]=i;
			score[i]=0;
		} 
		for (i=1;i<=m;++i){
			scanf("%d%d",&x,&y);
			Union(x,y);
		}
		for (i=1;i<=n;++i){
            FindSet(i);
			score[set[i]] = 1;
        }
		for (i=1;i<=n;++i)
			if (score[i]) ss++;
		printf("Case %d: %d\n",no,ss);
	}
	return 0;
}

int FindSet(int x){
	if (x != set[x])
		set[x]=FindSet(set[x]);
	return set[x];
}

void Union(int x,int y){
	x=FindSet(x);
	y=FindSet(y);
	set[y] = x;
	return;
}
