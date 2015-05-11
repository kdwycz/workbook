#include <iostream>
using namespace std;
int main()
{
  int k,i,f;
  while(cin>>k){
    f=0;
    for(i=0;i<65;++i){
      if((18+k*i)%65==0){
        f=1; break;
      }
    }
    if(f==0) cout<<"no"<<endl;
    else cout<<i<<endl;
  }
  return 0;
}