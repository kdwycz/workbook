//不断输出入度位0的点并删除该点和边。 无向图和有环图无法拓扑排序
//链式前项星存图

int queue[maxn],iq=0;
indreege[maxm] //入度
 
for (int i=1;i<=n;++i) 
	if (!indreege[i]) queue[iq++]=i;
for (i=0;i<iq;++i){
	for (k=head[queue[i]];k!=-1;k=edge[k].next){
		--indegree[edge[k].to];
		if (!indegree[edge[k].to]) queue[iq++]=egde[k].to; 
	}
}

for (i=0;i<iq;++i) cout<<quque[i]<<' ';