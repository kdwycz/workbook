#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
     bool operator ()(long long x, long long y){
        return x > y;
    }
};

int main()
{
	long long n,a,b,ans=0;
	priority_queue<long long,vector<long long>,cmp> heap;
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>a;
		heap.push(a);
	}
	while (n>1){
		a=heap.top(); heap.pop();
		b=heap.top(); heap.pop();
		ans+=a+b;
		heap.push(a+b);
		n--;
	}
	cout<<ans<<endl;
	return 0;
}
