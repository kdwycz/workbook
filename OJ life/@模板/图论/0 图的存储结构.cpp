
//邻接矩阵
int a[maxn][maxn];//其他省略。。。。 
 
//------------------------------------------------------------------------------
 
//前项星 
int head[maxn]; //存储起点为Vi的第一条边的位置 
struct node{ 
	int from;  //起点 
	int to;  //终点 
	int w;  //权值 
};
node edge[maxm];

bool cmp(node a,node b){
	if (a.from==b.from && a.to==b.to) return a.w<b.w;
	if (a.from==b.from) return a.to<b.to;
	return a.from<b.from;
} //比较函数

cin>>n>>m;
for (i=0;i<m;++i)
	cin>>edge[i].from>>edge[i].to>>edge[i].w;
sort(edge,edge+m,cmp);
head[edge[0].from]=0;
for (i=1;i<m;++i)
	if (edge[i].from!=edge[i-1].from)
		head[edge[i].from]from=i; //读入 
//遍历就是把head扫一遍 省略  
 
//------------------------------------------------------------------------------
 
//邻接表
struct edgenode{  //邻接表节点 
	int to;
	int w;
	edgenode *next;
};

struct vnode{  //起点表节点 
	int from;
	edgenode *first;
}

vnode adjlist[maxn];  //整个图的邻接表

//读入
cin>>i>>j>>w;
edgenode *p=new edgenode();
p->to=j;
p->w=w;
p->next=adjlist.first;
adjlist[i].first=p;

//遍历
for (i=i;i<n;++i)
	for (edgenode *k=adjlist[i].frist;k!=null;k=k->next)
		cout<<i<<' '<<k->to<<' '<<k->w<<endl;
 
//------------------------------------------------------------------------------
 
//STL中vector模拟链表
struct edgenode{
	int to;
	int w;
};
vector <node> map[maxn];

//读入
edgenode e;
cin>>i>>j>>w;
e.to=j;
e.w=w;
map[i].push_back(e);

//遍历
for (i=1;i<=n;++i)
	for (vector<node>::iterator k=map[i].begin():k!=map[i].end();k++ ){
		node t=*k;
		cout<<i<<' '<<t.to<<' '<<t.w<<endl;
	} 
	
//------------------------------------------------------------------------------

//链式前项星（撒花^-^）

int head[n];
struct edgenote{
	int to;
	int w;
	int next; //初始化位-1 
}  
edgenode edge[m];

//读入
cin>>i>>j>>w;
edge[k].to=j;
edge[k].w=w;
edge[k].next=head[i];
head[i]=k;

//遍历
for (i=1;i<=n;++i)
	for (k=head[i];k!=-1;k=edge[k].next)
		cout<<i<<' '<<edge[k].to<<' '<<egde[k].w<<endl;