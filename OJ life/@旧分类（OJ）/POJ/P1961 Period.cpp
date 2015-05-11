#include <iostream>
using namespace std;
string s;
int p[1000010],l,n=0,i,j,k;
int main()
{
	ios::sync_with_stdio(false);
	while (cin>>l && l){
		n++; cin>>s;
		cout<<"Test case #"<<n<<endl;
		j=-1; p[0]=-1;
		for (i=1;i<l;++i){
			while (j>-1 && s[i]!=s[j+1]) j=p[j];
			if (s[i]==s[j+1]) ++j;
			p[i]=j;	
			if (p[i]>-1){
				k=i-p[i];
				if ((i+1)%k==0) cout<<i+1<<' '<<(i+1)/k<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
