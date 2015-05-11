#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 12;

struct node{
	int du,no;
}frog[N];
int map[N][N],f;

bool cmp(node a,node b){
	return a.du>b.du;
}

bool make(){
	for (int j=1;frog[0].du;j++,frog[0].du--){
		frog[j].du--;
		if (frog[j].du<0) return false;
		map[frog[0].no][frog[j].no]=1;
		map[frog[j].no][frog[0].no]=1;
	}
	return true;
}

int main()
{
	int T,n;
	cin>>T;
	while (T--){
		memset(map,0,sizeof(map));
		memset(frog,0,sizeof(frog));
		cin>>n; f=true;
		for (int i=0;i<n;++i){
			cin>>frog[i].du;
			frog[i].no=i;
		}

		for (int i=1;i<=n;++i){
			sort(frog,frog+n,cmp);
			if (!make()){
				f=false;
				break;
			}
		}
			
		if (f){
			cout<<"YES\n";
			for (int i=0;i<n;++i){
				for (int j=0;j<n-1;++j)
					cout<<map[i][j]<<' ';
				cout<<map[i][n-1]<<endl;
			}
		}
		else
			cout<<"NO\n";

		if (T) cout<<endl;
	}
	return 0;
}
