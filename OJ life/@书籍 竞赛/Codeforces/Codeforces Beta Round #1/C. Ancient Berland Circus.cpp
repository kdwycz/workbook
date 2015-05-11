#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double PI=acos(-1.0);
const double EPS=1e-4;

double x[3],y[3],d[3],ang[3];
int i;

bool feq(double x,double y){
	return fabs(x-y)<EPS;
}

double fgcd(double a,double b){
	if(feq(a,0)) return b;
	if(feq(b,0)) return a;
	return fgcd(b,fmod(a,b));
}

double dis(int a,int b){
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int main()
{
	for(i=0;i<3;++i)
		cin>>x[i]>>y[i];
	for(i=0;i<3;++i)
		d[i]=dis(i,(i+1)%3);
		
	double p=(d[0]+d[1]+d[2])/2;
	double s=sqrt(p*(p-d[0])*(p-d[1])*(p-d[2]));
	double r=d[0]*d[1]*d[2]/(s*4);
	for(i=0;i<2;i++)
		ang[i]=acos(1-d[i]*d[i]/(2*r*r));
	ang[2]=2*PI-ang[0]-ang[1];
	double angle=fgcd(ang[0],fgcd(ang[1],ang[2]));
	printf("%.6f\n",r*r*sin(angle)/2*(2*PI/angle));
	return 0;
}
