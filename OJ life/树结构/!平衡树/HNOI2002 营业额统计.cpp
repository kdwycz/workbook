#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3f;
int pre[N],key[N],ch[N][2],root,tot1;
int n;

void NewNode(int &r,int father,int k)
{
    r=++tot1;
    pre[r]=father;
    key[r]=k;
    ch[r][0]=ch[r][1]=0;
}

void Rotate(int x,int kind)
{
    int y=pre[x];
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y])
      ch[pre[y]][ch[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
}

void Splay(int r,int goal){
    while(pre[r]!=goal){
        if(pre[pre[r]]==goal)Rotate(r,ch[pre[r]][0]==r);
        else{
            int y=pre[r];
            int kind=ch[pre[y]][0]==y;
            if(ch[y][kind]==r){
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else{
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    if(goal==0)root=r;
}

int Insert(int k){
    int r=root;
    while(ch[r][key[r]<k]){
        if(key[r]==k){
            Splay(r,0);
            return 0;
        }
        r=ch[r][key[r]<k];
    }
    NewNode(ch[r][key[r]<k],r,k);
    Splay(ch[r][key[r]<k],0);
    return 1;
}

int Get_pre(int x)
{
    int tmp=ch[x][0];
    if(tmp==0)return INF;
    while(ch[tmp][1])
      tmp=ch[tmp][1];
    return key[x]-key[tmp];
}

int Get_next(int x)
{
    int tmp=ch[x][1];
    if(0==tmp) return INF;
    while(ch[tmp][0])
      tmp=ch[tmp][0];
    return key[tmp]-key[x];
}

int main()
{
    scanf("%d",&n);
    root=tot1=0;
    int ans=0;
    for (int i=1;i<=n;++i){
        int num;
        if(~scanf("%d",&num)) num=0;
        if (i==1){
            ans+=num;
            NewNode(root,0,num);
            continue;
        }
        if (Insert(num)==0) continue;
        int a=Get_pre(root);
        int b=Get_next(root);
        ans+=min(a,b);
    }
    printf("%d\n",ans);
    return 0;
}
