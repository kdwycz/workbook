//图的 DFS BFS 图用链式前项星表示

bool s[maxn]={0}; //点是否被遍历 

void dfs (int x){
	s[x]=true;
	cout<<x;
	for (int i=head[x];i!=-1;i=edge[i].next)
		if (!s[edge[i].to]) dfs(edge[i].to);		
		
//------------------------------------------------------------------------------

bool s[maxn]; //同上 
viod bfs(int x){
	int quque[maxn]; //这个写法挺不错的。。。。。学习了 
	int iq=0;
	queue[iq++]=x;
	for (int i=0;i<iq;++i){
		cout<<quque[i];
		s[i]=true;																			
		for (k=head[queue[i]];k!=-1;k=edge[k].next)
			if (!s[edge[k].to]) quque[iq++]=edge[k].to;
	}
}
