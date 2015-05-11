#include <iostream>
using namespace std;
string s;
int n,i,l,r,c,t;
void print(int);
int main()
{
	cin>>n;
	while (n--){
		cin>>s;
		l=s.size();
		r=c=0;
		if (s[0]=='R' && s[1]<='9' && (t=s.find('C'))>0){
			for (i=t+1;i<l;++i) 
				c=c*10+(s[i]-'0');
			print(c);
			cout<<s.substr(1,t-1)<<endl;
		}
		else{
			for (i=0;i<l;++i)
				if (s[i]<'A'){
					t=i; break;
				}
			for (i=0;i<t;++i)
				r=r*26+(s[i]-'A'+1);
				cout<<'R'<<s.substr(t)<<'C'<<r<<endl;
		}
	}
	return 0;
}

void print(int x){
	if (x>0){
		if (x%26){
			print(x/26);
			cout<<char(x%26+'A'-1);
		}
		else{
			print(x/26-1);
			cout<<'Z';
		}
	}
	return;
}
