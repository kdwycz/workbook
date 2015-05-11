#include <iostream>
using namespace std;

const int MAXN=1<<5;
struct heap{
	int a[MAXN]={0},n=0;
	int pre(int p){return p-1>>1;};
	int left(int p){return (p<<1)+1;};
	int right(int p){return (p<<1)+2;};
	void ins(int x){
		int p;
		n++;
		for (p=n-1;p>0;)
			if (x<a[pre(p)]){
				a[p]=a[pre(p)];
				p=pre(p);
			}
			else break;
		a[p]=x;
	}
	int pop(){
		int p,x=a[0],tmp;
		for (p=0,n--;left(p)<n;){
			tmp=(right(p)<n && a[right(p)]<a[left(p)])?right(p):left(p);
			if (a[tmp]<a[n]){
				a[p]=a[tmp];
				p=tmp;   
			}
			else break;
		}
		a[p]=a[n];
		return x;
	}
};

int i,n,a;
heap h;

int main()
{
	cin>>n;
	for (i=0;i<n;++i){
		cin>>a;
		h.ins(a);
	}
	
	for (i=0;i<n;++i) cout<<h.pop()<<endl;
	
	return 0;
}
