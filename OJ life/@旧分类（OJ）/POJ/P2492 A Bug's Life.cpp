#include <cstdio>

int set[5010],offset[5010];
int n,m,k,i,j,x,y;
bool flag;

int FindSet(int x);
void Union(int x, int y);
int main()
{
	scanf("%d",&k);
	for (int i = 1; i <= k; ++i){
		scanf("%d%d", &n, &m);
		flag = true;
		for (j=1;j<=n;++j){
			set[j] = j;
			offset[j] = 0;
		}
		for (j = 1; j <= m; ++j){
			scanf("%d%d", &x, &y);
			if (flag)
				if (FindSet(x) != FindSet(y))
					Union(x, y);
				else
					if (offset[x] == offset[y]) flag=0;
		}
		if (flag)
			printf("Scenario #%d:\nNo suspicious bugs found!\n", i);
		else
			printf("Scenario #%d:\nSuspicious bugs found!\n", i);
		if (i != k) printf("\n");
	}
	return 0;
}

int FindSet(int x){
	if (x != set[x]){
		int temp=set[x];
		set[x] = FindSet(set[x]);
		offset[x]^=offset[temp];
	}
	return set[x];
}

void Union(int x, int y){
	int fx = FindSet(x);
	int fy = FindSet(y);
	set[fy] = fx;
	offset[fy] = offset[x]^offset[y]^1;
	return;
}
