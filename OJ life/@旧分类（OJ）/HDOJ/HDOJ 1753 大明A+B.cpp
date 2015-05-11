#include <iostream>
#include <cstring>
using namespace std;

const int M = 440;
string s1,s2;
int x1[M],x2[M],z1[M],z2[M];
int l1,l2,xl1,xl2,zl1,zl2,xl,zl;

int main()
{
	while (cin>>s1>>s2){
		memset(x1,0,sizeof(x1));
		memset(x2,0,sizeof(x2));
		memset(z1,0,sizeof(z1));
		memset(z2,0,sizeof(z2));
				
		l1 = s1.find('.');
		if (l1 == -1){
			s1+='.';
			l1 = s1.find('.');
		}
		l2 = s2.find('.');
		if (l2 == -1){
			s2+='.';
			l2 = s2.find('.');
		}
		
		for (int i = l1 - 1;i >= 0;--i)
			z1[l1-i-1] = s1[i] - '0';
		for (int i = l2 - 1;i >= 0;--i)
			z2[l2-i-1] = s2[i] - '0';
		for (int i = l1+1;i < s1.size();++i)
			x1[i-l1] = s1[i] - '0';
		for (int i = l2+1;i < s2.size();++i)
			x2[i-l2] = s2[i] - '0';

		xl1 = s1.size() - l1 - 1;
		xl2 = s2.size() - l2 - 1;
		zl1 = l1; zl2 = l2;		
		
		xl = xl1>xl2?xl1:xl2;
		zl = zl1>zl2?zl1:zl2;
				
		for (int i = xl;i;--i){
			x1[i] += x2[i];
			if (x1[i] > 9){
				x1[i] -= 10;
				++x1[i-1];
			}
		}
		z1[0] += x1[0];
		for (int i = 0;i < zl;++i){
			z1[i] += z2[i];
			if (z1[i] > 9){
				z1[i] -= 10;
				++z1[i+1];
			}
		}
		while (zl>=0 && z1[zl] == 0) zl--;
		while (xl>0 && x1[xl] == 0) xl--;
		
		for (int i = zl;i >= 0;--i)
			cout<<z1[i];
		if (zl == -1) cout<<'0';
		if (xl){
			cout<<'.';
			for (int i = 1;i <= xl;++i)
				cout<<x1[i];
		}		
		cout<<endl;	
	}
	return 0;	
} 
