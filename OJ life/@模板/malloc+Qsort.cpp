#include <cstdio>
#include <cstdlib>

int cmp(const void *a,const void *b){
	register const int *pa=(int *)a;
	register const int *pb=(int *)b;
	return *pa>*pb?1:*pa<*pb?-1:0;
}

int main()
{
	int *arr,n,i;
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	if (arr==NULL){
		printf("ERROR 2 !\n");
		exit(EXIT_FAILURE);
	}
	for (i=0;i<n;++i) scanf("%d",arr+i);
	
	qsort(arr,n,sizeof(int),cmp);
	
	for(i=0;i<n;++i) printf("%d ",arr[i]);
	
	free(arr);
	
	return 0;
}
