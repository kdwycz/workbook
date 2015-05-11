#include <cstdio>
#include <cstring>
const int MAX=9973;
int hash[MAX],c[MAX],n,i,max;
char s[63];

//万一在这里碰撞了怎么破？ 
unsigned int BKDRHash(char *str){
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;
	while (*str)
		hash = hash * seed + (*str++);
	return (hash & 0x7FFFFFFF);
}

void add(char *s){
	int t,k;
	while (*s=='0') s++;
	k=BKDRHash(s);
	t=k%MAX;
	while (c[t]!=k && hash[t]!=0)
		t=(t+1)%MAX;
	hash[t]++; c[t]=k;
	max=max<hash[t]?hash[t]:max;
}
int main()
{
	while (scanf("%d",&n)!=EOF){
		gets(s);
		max=0;
		memset(c,-1,sizeof(c));
		memset(hash,0,sizeof(hash));
		while(n--){
			gets(s);
			add(s);
		}
		printf("%d\n",max);
	}
	return 0;
}
