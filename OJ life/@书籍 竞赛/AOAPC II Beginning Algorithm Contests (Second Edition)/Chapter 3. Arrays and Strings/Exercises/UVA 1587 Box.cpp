#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int w,h;
}box[6];

bool operator !=(node a,node b){
    return !(a.w==b.w && a.h==b.h);
}

bool cmp(node a,node b){
    return a.w*a.h<b.w*b.h;
}

int main()
{
    while (cin>>box[0].w>>box[0].h){
        if (box[0].w>box[0].h) swap(box[0].w,box[0].h);
        for (int i=1;i<6;++i){
            cin>>box[i].w>>box[i].h;
            if (box[i].w>box[i].h) swap(box[i].w,box[i].h);
        }
        sort(box,box+6,cmp);
        bool flag=true;
        if (box[0]!=box[1] || box[2]!=box[3] || box[4]!=box[5])
            flag=false;
        if (box[0].w!=box[2].w || box[0].h!=box[4].w || box[2].h!=box[4].h)
            flag=false;
        if (flag)
            cout<<"POSSIBLE\n";
        else
            cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
