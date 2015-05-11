#include <iostream>
#include <string> 
using namespace std;
int main(int argc, char *argv[])
{
	string a; int b,i,j;
	cin>>a;
	while (a!="0"){
		b=0; 
		for(i=0;i<a.length();++i) b+=a[i]-'0';	 
		j=b;
		while (b>9){
			j=0;
			while (b){
				j+=(b%10); 
				b/=10; 
			}
			b=j;
		}
		cout<<j<<endl;
		cin>>a;
	}
	return 0;
}

/*
极致简洁高效的 AC 代码！～～～
#include<stdio.h>
int main()
{
    int a,c;
    for(;scanf("%1d",&a),a>0;printf("%d\n",--a%9u+1))
        while((c=getchar())-48u<10)
            a+=c-48;
    return 0;
}
说明：
1、能够处理很长位数的整数而无需使用数组。
2、速度极致，尽量采用高效的getchar，不采用循环反复缩短位数的方法，只是一个对9求余，理论依据…………自己想啊！
3、因为一接收到0就认为输入结束，因此这个代码能够AC，说明不存在以0开头的多位整数。

#include<stdio.h>
int main()
{
	int i,m;
    char s[1000];
    while(scanf("%s",s)==1&&s[0]!='0'){
         for(m=i=0;s[i];i++)
                 m+=s[i]-'0';
    printf("%d\n",m%9==0?9:m%9);    //很靓啊哈~
    }
    return 0;
} 
*/