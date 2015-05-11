#include <cstdio>
int main()
{
	int n,sum,i;
	printf("PERFECTION OUTPUT\n");
	while (scanf("%d",&n)!=EOF && n){
		printf("%5d  ",n);
		sum=0;
		for (i=1;i<n;++i)
			if (n%i==0)
				sum+=i;
		if (sum<n)  printf("DEFICIENT\n");
		if (sum==n) printf("PERFECT\n");
		if (sum>n)  printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
} 
