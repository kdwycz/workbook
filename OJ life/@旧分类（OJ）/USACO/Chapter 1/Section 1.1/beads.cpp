/* 
ID:kdwycz
PROG:beads
LANG:C++
*/

#include <fstream>
using namespace std;
int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	string s; char c=0;
	int n,i,a=0,b=0,w=0,ans=0;
	fin>>n>>s;
	s+=s;
	for (i=0;i<n<<1;i++)
		if (s[i]=='w') b++,w++;
		else if (s[i]==c) b++,w=0;
  			 else{
				 if (a+b>ans) ans=a+b;
				 a=b-w; b=w+1; w=0; c=s[i];
				 }
	if (a+b>ans) ans=a+b;
	fout<< (ans>n?n:ans) <<endl;
	return 0;
}
