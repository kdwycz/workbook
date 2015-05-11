#include <cstdio>
#define Lowbit(x) (x&(-x))
const int M=32010;
const int N=15000;
int arr[M]={0},ans[N]={0};
int n,x,y;

void Update(int x){
	for (int i=x;i<=M;i+=Lowbit(i))
		arr[i]+=1;
}

int Getsum(int x){
	int aa=0;
	for (int i=x;i;i-=Lowbit(i))
		aa+=arr[i];
	return aa;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d%d",&x,&y);
		x++;
		ans[Getsum(x)]++;
		Update(x);
	}
	for (int i=0;i<n;++i)
		printf("%d\n",ans[i]);
	return 0;
} 
