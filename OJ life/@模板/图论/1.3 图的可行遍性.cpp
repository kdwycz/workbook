int ans[maxn];
int ansi=0; //记录边 
bool visit[2*maxm]; //无向图、、、边存两次 
void dfs(int now){
	for (int k=head[now];k!=-1;k=edge[k].next)
		if (!visit[t]){
			visit[k]=true;
			visit[k^1]=true; //标记反向边 注释1 
			dfs(edge[k].to);
			ans[ansi++]=k;
		} 
}  
//注释1：因为链式前项星存无向边时，edge[i]存a->b edge[i+1]存 b->a。 ^1运算