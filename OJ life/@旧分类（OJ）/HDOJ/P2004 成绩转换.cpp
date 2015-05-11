#include<iostream>
using namespace std;
int main()
{
    int i;
    while (cin>>i){
        if (i<0) cout<<"Score is error!"<<endl;
            else if (i<60) cout<<"E"<<endl;
                    else if (i<70) cout<<"D"<<endl;
                    else if (i<80) cout<<"C"<<endl;
                        else if (i<90) cout<<"B"<<endl;
                            else if (i<=100) cout<<"A"<<endl;
                                else cout<<"Score is error!"<<endl; 
    }
    return(0);
}