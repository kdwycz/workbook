#include <iostream>
#include <cstring>
using namespace std;
bool map[25][128];
int n;
int main()
{
	string s;
	cin>>s;
	int k=0;
	memset(map,0,sizeof(map));
	for (int i=0;i<s.size();i++){	
		if ((s[i]>='a' &&s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			map[k][s[k]]=1;
			++k;
		}
		else if (s[i]=='*'){
			for (int j='a';j<='z';++j)
				map[k][j]=1;
			for (int j='A';j<='Z';++j)
				map[k][j]=1;
			++k;
		}
		else if (s[i]=='['){
			if (s[i+2] != '-')
				while (s[++i] != ']')
					map[k][s[i]]=1;
			else
				while (s[++i]!=']'){
					for (int j=s[i];j<=s[i+2];++j)
						map[k][j]=1;
					i+=2;
				}
			++k;
		}
	}			
		cin>>n;
		while (n--){
			cin>>s;
			int flag=0;
			for ( int i=0; i<=s.size() && flag==0;++i){
				for (int j=0;j<k;++j){
					if (map[j][s[i+j]]==0) 
						break;
					if (k-j==1) flag=1;
				}
			}
			if (flag==1)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	return 0;
}
