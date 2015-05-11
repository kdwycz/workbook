//我2死了。。。字符串当做栈来用，入栈时用+=和下标+1，出栈时只把下标-1有毛用啊！！！ 
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int flag,n,i,j,k,l,s[1000]; //S是输出队列 
	string a,b,c; //C是栈 
	while (cin>>n){
		memset(s,0,sizeof(s));
		cin>>a>>b; flag=1;
		i=0; j=0; k=-1; l=0; c="";
		while (a[i]!=b[j]){
	 		++k; c+=a[i++]; s[l++]=0;
		}  //初始化 入栈 
		++i; ++j; s[l++]=0; s[l++]=1; //C+=a[i++]; ++k; --k; 冗余运算 
		while ((j<n)&&(flag))
			if ((c[k]==b[j])&&(k>=0)) {++j; c.erase(k,1); --k; s[l++]=1;}
			else{
				while ((a[i]!=b[j])&&(i<n)){
					++k; c+=a[i++]; s[l++]=0;
				}
				
				if (i!=n) {++i; ++j; s[l++]=0; s[l++]=1; }	
				else flag=0;
			}
		if (flag){
			cout<<"Yes.\n";
			for (i=0;i<l;++i)
				if (s[i]) cout<<"out\n";
				else      cout<<"in\n";
			cout<<"FINISH\n";
		}
		else cout<<"No.\nFINISH\n";
	}
	return 0;
}
