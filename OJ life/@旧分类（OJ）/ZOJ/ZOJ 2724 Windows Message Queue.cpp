#include <iostream>
using namespace std;

const int MAXN=60010;
struct heap{
	int a[MAXN]={0},n=0;
	string s[MAXN];
	int pre(int p){return p-1>>1;};
	int left(int p){return (p<<1)+1;};
	int right(int p){return (p<<1)+2;};
	void ins(int x,string s1){
		int p;
		n++;
		for (p=n-1;p>0;)
			if (x<a[pre(p)]){
				a[p]=a[pre(p)];
				s[p]=s[pre(p)];
				p=pre(p);
			}
			else break;
		a[p]=x;
		s[p]=s1;
	}
	string pop(){
		if (!n) return "EMPTY QUEUE!";
		int p,tmp; string x=s[0];
		for (p=0,n--;left(p)<n;){
			tmp=(right(p)<n && a[right(p)]<a[left(p)])?right(p):left(p);
			if (a[tmp]<a[n]){
				a[p]=a[tmp];
				s[p]=s[tmp];
				p=tmp;   
			}
			else break;
		}
		a[p]=a[n];
		s[p]=s[n];
		return x;
	}
};

int main()
{
	heap h; int x;
	string s1,s2;
	while (cin>>s1){
		if (s1=="GET")
			cout<<h.pop()<<endl;
		else{
			cin>>s1>>s2>>x;
			s1=s1+' '+s2;
			h.ins(x,s1);
		}
	}
	return 0;
}
