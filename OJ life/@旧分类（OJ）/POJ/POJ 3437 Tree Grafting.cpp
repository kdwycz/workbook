#include <iostream>
using namespace std;
string s;
int i,n=0,height1,height2;

void work(int level1,int level2,int son){
	int tempson=0;
	while (s[i]=='d'){
		i++; tempson++;
		work(level1+1,level2+tempson,tempson);
	}
	height1=level1>height1?level1:height1;
	height2=level2>height2?level2:height2;
	i++;
}

int main()
{
	while (cin>>s && s!="#"){
		i=height1=height2=0;
		work(0,0,1);
		cout<<"Tree "<<++n<<": "<<height1<<" => "<<height2<<endl;
	}
	return 0;
}
