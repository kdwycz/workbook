#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

const int M=1010;

struct cc{
	int x,y;
}cite[M*M];
long long arr[M];
int t,n,m,k;

void Update(int x){
	for (int i=x;i<=M;i+=Lowbit(i))
		arr[i]++;
}

long long Getsum(int x){
	long long aa=0;
	for (int i=x;i;i-=Lowbit(i))
		aa+=arr[i];
	return aa;
}

bool cmp(cc a,cc b){
	if (a.y==b.y)
		return a.x>b.x;
	else
		return a.y>b.y;
}

int main()
{
	scanf("%d",&t); int i=0;
	while (~scanf("%d%d%d",&m,&n,&k)){
		for (int j=0;j<k;++j){
			scanf("%d%d",&cite[j].x,&cite[j].y);
		}
		sort(cite,cite+k,cmp);
		memset(arr,0,sizeof(arr));
		long long ans=0ll;
		for (int j=0;j<k;++j){
			ans+=Getsum(cite[j].x-1);
			Update(cite[j].x);
		}
		printf("Test case %d: %lld\n",++i,ans);
	}
	return 0;
}
