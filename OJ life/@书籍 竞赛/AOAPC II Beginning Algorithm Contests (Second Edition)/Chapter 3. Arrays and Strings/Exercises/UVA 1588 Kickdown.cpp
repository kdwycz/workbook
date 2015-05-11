#include <iostream>
using namespace std;

string s1,s2;
int i,j,flag,l1,l2,l3;

int main()
{
    while (cin>>s1>>s2){
        l1=l2=l3=s1.size()+s2.size();

        for (i=0;i<s1.size();++i){
            j=0; flag=true;
            while (i+j<s1.size() && j<s2.size()){
                if (s1[i+j]=='2' && s2[j]=='2'){
                    flag=false; break;
                }
                j++;
            }
            if (flag){
                l1=max(s1.size(),i+s2.size());
                break;
            }
        }

        swap(s1,s2);
        for (i=0;i<s1.size();++i){
            j=0; flag=true;
            while (i+j<s1.size() && j<s2.size()){
                if (s1[i+j]=='2' && s2[j]=='2'){
                    flag=false; break;
                }
                j++;
            }
            if (flag){
                l2=max(s1.size(),i+s2.size());
                break;
            }
        }

        cout<<min(min(l1,l2),l3)<<endl;
    }
    return 0;
}
