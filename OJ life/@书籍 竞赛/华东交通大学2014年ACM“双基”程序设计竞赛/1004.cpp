#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T,n,a[1010];
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=0;i<n;++i)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d",a[0]);
        for (int i=1;i<n;++i)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}
