#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,a[1000],b[1000],c[10],num=0;
	while (cin>>n && n){
		cout<<"Game "<<++num<<":\n";
		for (int i=0;i<n;++i)
			cin>>a[i];
		while (1){
			int flag=0,x=0,y=0;
			memset(c,0,sizeof(c));
			for (int i=0;i<n;++i){
				cin>>b[i];
				flag|=b[i];
				c[a[i]]++;
			}
			if (!flag) break;
			for (int i=0;i<n;++i)
				if (a[i]==b[i]){
					x++;
					c[a[i]]--;
				}
			for (int i=0;i<n;++i)
				if (a[i]!=b[i] && c[b[i]]){
					y++;
					c[b[i]]--;
				}
			cout<<"    ("<<x<<','<<y<<")\n";
		}
	}
	return 0;
}
