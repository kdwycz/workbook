#include <iostream>
#include <algorithm>
using namespace std;
int prime(int);
int l,n,m,i,a[500010],leftn,rightn,midn; 
int main(){
	std::ios::sync_with_stdio(false);
	while (cin>>l>>n>>m){
		for (i=1;i<=n;++i) cin>>a[i];
		a[0]=0; a[n+1]=l; 
		sort (a+1,a+n+1);
		leftn=1; rightn=l; n++;
		while (leftn<=rightn){
			midn=(leftn+rightn)/2;
			if (prime(midn)) rightn=midn-1;
			else leftn=midn+1;
		}
		cout<<leftn<<endl;
	}
	return 0;
}

int prime(int b){ 
	if (b*m<l) return 0;
	int i,j,k;
	i=0; k=0;
	while (i<n){
		if (a[i+1]-a[i]>b) return 0;
		else{
			i++; k++; 
			if (k>m) return 0;
			j=i;
			while ((a[j+1]-a[i-1]<=b)&&(j<n)) 
				j++;
			i+=j-i; 			
		}
	}
	return 1;
}

