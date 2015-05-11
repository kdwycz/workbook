#include <cstdio>
int main()
{
    int n,k,ans;
    while (~scanf("%d",&n)){
        ans=0;
        while (n--){
            scanf("%d",&k);
            ans^=k;
        }
        if (ans) printf("Win\n");
        else printf("Lose\n");
    }
    return 0;
}
