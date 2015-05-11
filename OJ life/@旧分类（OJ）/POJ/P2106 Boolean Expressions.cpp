#include <iostream>
using namespace std;

const int N=110;
string s;
int val[N],op[N],vtop,otop;

void insert(int);
void calc();
int main()
{
	int loop=0;
	while (getline(cin,s)){
		vtop=otop=0;
		for (int i=0;i<s.size();++i)
			switch(s[i]){
				case '(':
					op[otop++]=0;
					break;
				case ')':
					while (otop && op[otop-1]!=0) calc();
					--otop;
					insert(val[--vtop]);
					break;
				case '!':
					op[otop++]=3;
					break;
				case '&':
					while (otop && op[otop-1]>=2) calc();
					op[otop++]=2;
					break;
				case '|':
					while (otop && op[otop-1]>=1) calc();
					op[otop++]=1;
					break;
				case 'V':
					insert(1);
					break;
				case 'F':
					insert(0);
					break;
				default:
					break;	
			}
		while (otop) calc();
		cout<<"Expression "<<++loop<<": "<<(val[0]?'V':'F')<<endl;
	}
	return 0;
}

void insert(int x){
	while (otop && op[otop-1]==3){
		x=!x; --otop;
	}
	val[vtop++]=x;
}

void calc(){
	int a=val[--vtop];
	int b=val[--vtop];
	int o=op[--otop];
	if (o==1)
		insert(a|b);
	else
		insert(a&b);
}
