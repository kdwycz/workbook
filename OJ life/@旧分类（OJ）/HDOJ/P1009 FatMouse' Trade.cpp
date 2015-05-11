#include <iostream>
#include <algorithm> 
using namespace std;
struct house{
	int j,f;
	double ii;
};
int cmp(house,house); 
house a[1100];
int m,n,i,f,j; double bean;
int main(int argc, char *argv[])
{
	cout.precision(3);
	cout.setf(ios::fixed);
	while((cin>>m>>n)&&(m!=-1)){
 		for (i=1;i<=n;++i){
			cin>>a[i].j>>a[i].f;
			if (!a[i].f) a[i].ii=1001;
			else a[i].ii=(double)a[i].j/(double)a[i].f;
 		} 
		i=1; bean=0; j=m;
		sort(a+1,a+n+1,cmp);
		while ((j)&&(i<=n)){
			if (a[i].ii>1000) bean+=a[i].j;
			else if(a[i].f>j){
				bean+=j*a[i].ii; j=0;
			}
			else{
				bean+=a[i].j; j-=a[i].f;
			}
			++i;
		}
		cout<<bean<<endl;
	}
	return 0;
}

int cmp(house a,house b){
	return a.ii>b.ii;
}
