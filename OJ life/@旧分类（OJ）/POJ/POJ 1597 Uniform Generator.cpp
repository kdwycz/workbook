#include <cstdio>
#include <cstring>
int main()
{
	bool flag,arr[110000];
	int a,i,m,n;
	while (scanf("%d%d",&m,&n)!=EOF){
		memset(arr,false,sizeof(arr));
		a=0; i=1; arr[0]=1; flag=true;
		while (flag && i<n){
			i++;
			a=(a+m)%n;
			if (arr[a]) flag=false;
			arr[a]=true;	
		}
		if (flag)
			printf("%10d%10d    Good Choice\n\n",m,n);
		else
			printf("%10d%10d    Bad Choice\n\n",m,n);
		
	} 
	return 0;
} 
