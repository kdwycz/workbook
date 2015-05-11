/*喜闻乐见的TLE 
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int a,b,i,s;
     while (cin>>a>>b){
         s=a%10;
         for(i=1;i<b;++i){
             s*=a;
             s%=10;
         }
         cout<<s<<endl;
     }
    return 0;
}
*/ 

/*快速幂 
#include <iostream>
using namespace std;
int qm(int a,int b){
    int s;
    if (b==1) return a;
    s=qm(a,b/2); s*=s;
    if (b%2==1) s*=a;
    return s%10; 
}
int main(int argc, char *argv[])
{
    int a,b,i,s;
     while (cin>>a>>b){
         cout<<qm(a%10,b)<<endl;
     }
    return 0;
}
*/

//只让答最后一位，找规律显然最简单，时间复杂度最优。数学规律，最简解决之道。 
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
   int result[10][5]={{0,0,0,0,0},{0,1,1,1,1},
                      {0,2,4,8,6},{0,3,9,7,1},
                      {0,4,6,4,6},{0,5,5,5,5},
                      {0,6,6,6,6},{0,7,9,3,1},
                      {0,8,4,2,6},{0,9,1,9,1}};
   int a,b;
   while(cin>>a>>b){
           a%=10;
           cout<<result[a][b%4==0?4:b%4]<<endl;
   }
    return 0;
}
