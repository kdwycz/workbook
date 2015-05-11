#include <cstdio>

int set[100010],offset[100010];
int k,i,n,m,x,y,fx,fy;
char s;

int FindSet(int x);
void Union(int x,int y,int fx,int fy);
int main()
{
	scanf("%d",&k);
	while (k--){
		scanf("%d %d",&n,&m);
		for (i=1;i<=n;++i){
			set[i]=i;
			offset[i]=0; 
		}
		for (i=1;i<=m;++i){
			getchar();
			scanf("%c %d %d",&s,&x,&y);
			fx=FindSet(x);
			fy=FindSet(y);
			if (s == 'A')
				if (fx != fy)
					printf("Not sure yet.\n");
				else
					if (offset[x] == offset[y])
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
			else
				Union(x,y,fx,fy);
		}
	}
	return 0;
}

int FindSet(int x){
	if (set[x] != x){
		int temp=set[x];
		set[x]=FindSet(set[x]);
		offset[x]^=offset[temp];
	}
	return set[x];
}

void Union(int x,int y,int fx,int fy){
	set[fx]=fy;
	offset[fx]=offset[x]^offset[y]^1; 
	return;
}
