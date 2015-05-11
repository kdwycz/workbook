#include <iostream>
using namespace std;
struct map{
	bool m[6][6][2];
	int x,step;
}queue[800010],tem;

int main()
{
	string s; int i,j,k,l;
	tem.x=tem.step=0;
	for (i=1;i<=4;++i){
		cin>>s;
		for (j=0;j<4;++j)
			if (s[j]=='b'){
				tem.x++;
				tem.m[i][j+1][1]=1;
				tem.m[i][j+1][0]=1;
			}
			else{
				tem.m[i][j+1][1]=0;
				tem.m[i][j+1][0]=1;
			} 
	}
	
	if (tem.x==16 || tem.x==0){
		cout<<'0'<<endl;
		return 0;
	}
	
	int so=0,fa=0;
	queue[0]=tem;
	while (fa<=so && so<=800001){
		for (i=1;i<=4;++i)
			for (j=1;j<=4;++j){
				if (tem.m[i][j][0]){
					tem.m[i][j][0]=0;
					tem.m[i][j][1]^=1;
					tem.m[i-1][j][1]^=1;
					tem.m[i+1][j][1]^=1;
					tem.m[i][j-1][1]^=1;
					tem.m[i][j+1][1]^=1; 
					tem.x=0; tem.step++;
					for (k=1;k<=4;++k)
						for (l=1;l<=4;++l)
							tem.x+=tem.m[k][l][1];
					if (tem.x==0 || tem.x==16){
						cout<<tem.step<<endl;
						return 0;
					}
					queue[++so]=tem;
					tem=queue[fa];
				}
			}
		tem=queue[++fa];
	}
	cout<<"Impossible\n";
	return 0;
}
