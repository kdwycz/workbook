#include <iostream>
#include <cstring>
using namespace std;
const int MAX=50021;
int f[MAX],g[MAX];
int a,b,c,d,pin[101],i,j,sum,s,p;

int hash(int k){
    int t=k%MAX;
    if (t<0) t+=MAX;
    while (f[t]!=0 && g[t]!=k)
        t=(t+1)%MAX;
    return t;
}

int main()
{
    for (i=1;i<=100;++i)
        pin[i]=i*i;
    while (cin>>a>>b>>c>>d){
        if ((a>0 && b>0 && c>0 && d>0) || (a<0 && b<0 && c<0 && d<0)){
            cout<<"0\n";
            continue;
        }
        memset(f,0,sizeof(f)); sum=0;
        for (i=1;i<=100;++i)
            for (j=1;j<=100;++j){
                s=a*pin[i]+b*pin[j];
                p=hash(s);
                g[p]=s;
                f[p]++;
            }
        for (i=1;i<=100;++i)
            for (j=1;j<=100;++j){
                s=-(c*pin[i]+d*pin[j]);
                p=hash(s);
                sum+=f[p];
            }
        cout<<(sum<<4)<<endl;    
    }    
    return 0;
}

/*
#include <iostream>
#include <cstring>
using namespace std;
int a,b,c,d,pin[101],hash[2000010],i,j,sum;
int main()
{
    for (i=1;i<=100;++i)
        pin[i]=i*i;
    
    while (cin>>a>>b>>c>>d){
        if ((a>0 && b>0 && c>0 && d>0) || (a<0 && b<0 && c<0 && d<0)){
            cout<<"0\n";
            continue;
        }
        memset(hash,0,sizeof(hash)); sum=0;
        for (i=1;i<=100;++i)
            for (j=1;j<=100;++j)
                hash[a*pin[i]+b*pin[j]+1000000]++;
        for (i=1;i<=100;++i)
            for (j=1;j<=100;++j)
                sum+=hash[1000000-(c*pin[i]+d*pin[j])];
        cout<<sum*16<<endl;
    }
    return 0;
}
*/ 
