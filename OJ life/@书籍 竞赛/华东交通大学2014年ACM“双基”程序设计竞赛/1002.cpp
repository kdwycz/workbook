#include <cstdio>
#include <cmath>
int main()
{
    double x1,x2,y,vx,vy,t,t1,g=9.8;
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%lf%lf%lf%lf",&x1,&x2,&y,&vx);
        if (x1==x2 && int(y)==0){
            printf("0.00\n");
            continue;
        }
        if (x1==x2 && int (vx)==0){
            t=sqrt(2*y/g);
            vy=g*t;
            printf("%.2lf\n",vy);
            continue;
        }
        if (x1>=x2 || int(vx)==0){
            printf("Xue di so diao can fly\n");
            continue;
        }
        t=(x2-x1)/vx;
        vy=y/t+g*t/2;
        printf("%.2lf\n",vy);
    }
    return 0;
}
