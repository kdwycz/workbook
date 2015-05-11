#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	double t,d,h,a,b;
	int i,j,k,flag;
	char c1,c2;
	while(cin>>c1 && c1 !='E')
	{
		i=j=k=1;
		cin>>a>>c2>>b;
		if (c1=='T'){ i=0; t=a; }
		if (c1=='D'){ j=0; d=a; }
		if (c1=='H'){ k=0; h=a; }
		if (c2=='T'){ i=0; t=b; }
		if (c2=='D'){ j=0; d=b; }
		if (c2=='H'){ k=0; h=b; }
		if (i) t=h-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10.0);
		if (j) d=1/(1/273.16-log(((h-t)/0.5555+10)/6.11)/5417.753)-273.16;
		if (k) h=t+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10.0);
		printf("T %.1f D %.1f H %.1f\n",t,d,h);
	}
	return 0;
}
