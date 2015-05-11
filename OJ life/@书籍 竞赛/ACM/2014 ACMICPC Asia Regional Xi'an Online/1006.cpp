//上下左右 前后
#include<cstdio>
#include<cmath>
#include<cstring>
#define Max 5000000
bool visit[20000000]={0};
struct Node{
	int a[6],step;
}map[Max],temp,end;
bool equal(Node &x,Node &y){
	for(int i=0;i<6;i++)
	if(x.a[i]!=y.a[i]) return false;
	return true;
}
int hash(Node x)
{
	int sum=0;
     for(int i=0;i<6;i++){
     	sum+=x.a[i]*pow(10,i);
     }
     return sum;
}
bool Ispos(){
 	int x=map[0].a[0],y=map[0].a[2],a=map[1].a[0],b=map[1].a[1],flag=0;
 	if(x==a&&y==b) flag=1;
 	else if(x==b&&y==a) flag=1;
 	if(!flag) return false;
 	x=map[0].a[1],y=map[0].a[3],a=map[1].a[1],map[1].a[3],flag=0;
 	if(x==a&&y==b) flag=1;
 	else if(x==b&&y==a) flag=1;
	x=map[0].a[4],y=map[0].a[5],a=map[1].a[4],b=map[1].a[5],flag=0;
 	if(x==a&&y==b) flag=1;
 	else if(x==b&&y==a) flag=1;
 	if(!flag) return false;
 	return true;
}
int main(){
	while(~scanf("%d%d%d%d%d%d",&map[0].a[0],&map[0].a[2],&map[0].a[3],&map[0].a[1],&map[0].a[4],&map[0].a[5])){
	memset(visit,0,sizeof(visit));
	scanf("%d%d%d%d%d%d",&end.a[0],&end.a[2],&end.a[3],&end.a[1],&end.a[4],&end.a[5]);
	map[0].step=0; end.step=0;
	int exdir=0,nodedir=0,flag=1;
	if(equal(map[0],end)){
		printf("%d\n",0);
	 continue;
	}
	while(nodedir<=exdir&&exdir<Max&&flag){
		for(int i=0;i<4;i++){
			temp=map[nodedir];
			//像前
			if(!i){
				int x,y;
				x=temp.a[0]; temp.a[0]=temp.a[5];
				y=temp.a[4]; temp.a[4]=x;
				x=temp.a[2]; temp.a[2]=y;
				temp.a[5]=x;
			}
			//向后
			else if(i==1){
				int x=temp.a[5]; temp.a[5]=temp.a[0];
				int y=temp.a[2]; temp.a[2]=x;
				x=temp.a[4]; temp.a[4]=y;
				temp.a[0]=x;
			}
			//左
			else if(i==2){
				int x=temp.a[3]; temp.a[3]=temp.a[0];
				int y=temp.a[2]; temp.a[2]=x;
				x=temp.a[1]; temp.a[1]=y;
				temp.a[0]=x;
			}
			//右
			else{
				int x=temp.a[1]; temp.a[1]=temp.a[0];
				int y=temp.a[2]; temp.a[2]=x;
				x=temp.a[3]; temp.a[3]=y;
				temp.a[0]=x;
			}
			temp.step++;
			if(equal(temp,end)){
				printf("%d\n",temp.step);
				flag=0;
				break;
			}
			if(!visit[hash(temp)]) {
			 map[++exdir]=temp;
    		 visit[hash(temp)]=1;
			}
		}
		nodedir++;
	}
	if(flag) printf("-1\n");

	}

	return 0;
}
