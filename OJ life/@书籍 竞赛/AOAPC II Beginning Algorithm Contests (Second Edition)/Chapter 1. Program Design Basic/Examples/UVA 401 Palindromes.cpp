#include <iostream>
using namespace std;

const string s1="123456789       ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s2="1SE Z  8        A   3  HIL JM O   2TUVWXY5";
const string ss[4]={" -- is not a palindrome.\n\n",
					" -- is a regular palindrome.\n\n",
					" -- is a mirrored string.\n\n",
					" -- is a mirrored palindrome.\n\n"};
string s,temp;
int i,b,b1,b2,len;
int main()
{
	while (cin>>s){
		b1=1; b2=2; b=1; temp=s;
		len=s.size();
		for (i=0;i<len;++i)
			if (s[i]=='0') s[i]='O';
		for (i=0;i<=len/2;++i){
			if (s[i]!=s[len-i-1] && s1[s[i]-49]!=s2[s[len-i-1]-49]){
				b=0; break;
			}
			if (b2 && s[i]==s[len-i-1] && s1[s[i]-49]!=s2[s[len-i-1]-49]) b2=0;
			if (b1 && s1[s[i]-49]==s2[s[len-i-1]-49] && s[i]!=s[len-i-1]) b1=0;
		}
		if (len==1 && s2[s[0]-49]!=' ') b2=2; 
		if (!b) cout<<temp<<ss[b];
		else cout<<temp<<ss[b1+b2];
	}
	return 0;
}
