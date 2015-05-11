#include<iostream>
using namespace std;
int main ()
{
   int n,i,yhs,ans;
   int a[105];
   while(cin>>n && n){
      for(yhs=0,i=1;i<=n;i++){
         cin>>a[i];
         yhs^=a[i];
      }
      for(ans=0,i=1;i<=n;i++)
         if((yhs^a[i])<a[i])
           ans++;
      cout<<ans<<endl;
    }
    return 0;
}
