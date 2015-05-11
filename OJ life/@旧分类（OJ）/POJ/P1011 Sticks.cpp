#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int a[70],b[70],n,i,sum,minn;
int cmp(int a,int b){return a>b;}
bool dfs(int o,int p,int q);
int main()
{
	while (cin>>n && n){
		memset(b,0,sizeof(b)); sum=0;
		for (i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n,cmp);
		for (minn=a[0];minn<sum;++minn)
			if (sum%minn==0 && dfs(0,minn,sum)) break;
		cout<<minn<<endl;
	}
	return 0;
}

bool dfs(int o,int p,int q){
	if (q==minn) return true;
	for (int i=o;i<n;++i)
		if (!b[i] && a[i]<=p){
			b[i]=true;
			if (a[i]==p)
				{if (dfs(0,minn,q-a[i])) return true;} 
			else
				if (dfs(i+1,p-a[i],q-a[i])) return true;
			b[i]=false;
			if (a[i]==p) return false;	//¼ôÖ¦2 
			if (q==sum) return false;	//¼ôÖ¦3 
			if (p==minn) return false;	//¼ôÖ¦4 
			while (a[i+1]==a[i] && i<n) i++;  //¼ôÖ¦5 
		}
	return false;
}
