//4288 Coder 线段树 vector偷懒做法
/*
题意：给一个序列，每次有3种操作：
    1、往有序集合中增加一个原素x
    2、把集合中的元素x
    3、查询集合中下标%5=3的元素的总和

思路：vector
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std;
char op[5];
int n,x;
__int64 ans;

vector<int>V;
int main(){
  int i;
  while(scanf("%d",&n)!=EOF){
    V.clear();
    while(n--){
      scanf("%s",op);
      if(op[0] == 's'){
        ans = 0;
        for(i = 2; i < V.size(); i+=5)
          ans += V[i];
        printf("%I64d\n",ans);
      }
      else{
        scanf("%d",&x);
        if(op[0] == 'a')
          V.insert(lower_bound(V.begin(),V.end(),x),x);
        else
          V.erase(lower_bound(V.begin(),V.end(),x));
      }
    }	
  }
  return 0;
}