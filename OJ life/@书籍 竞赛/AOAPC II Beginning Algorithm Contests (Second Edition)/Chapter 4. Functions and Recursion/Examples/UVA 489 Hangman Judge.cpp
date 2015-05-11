#include <iostream>
#include <cstring>
using namespace std;

string s1,s2;
int flag,n,win,lose,arr[100];

int main()
{
    while (cin>>n && n!=-1){
        memset(arr,0,sizeof(arr));
        lose=0;
        cin>>s1>>s2;
        win=s1.size();
        for (int i=0;i<s2.size();++i){
            flag=1;
            for (int j=0;j<=s1.size();++j)
                if (!arr[j] && s2[i]==s1[j]){
                    win--; arr[j]=1; flag=0;
                }
            if (flag) lose++;
            if (win==0 || lose==7) break;
        }
        cout<<"Round "<<n<<endl;
        if (win==0)
            cout<<"You win.\n";
        else if (lose==7)
            cout<<"You lose.\n";
        else
            cout<<"You chickened out.\n";
    }
    return 0;
}
