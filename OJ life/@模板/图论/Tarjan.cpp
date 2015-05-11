int dfn[N]={0},low[N],stap[N]={0},belong[N]; 
bool stack[N]={0}; 
int stop=0,bcnt=0,dindex=0;

void Tarjan(int i){
	int k;
	dfn[i]=low[i]=++dindex;
	stack[i]=true;
	stap[++stop]=i;
	for (int j=head[i];j;j=next[j]){
		k=link[j];
		if (!dfn[k]){
			Tarjan(k);
			low[i]=low[i]>low[k]?low[k]:low[i];
		}
		else if (stack[k] && dfn[k]<low[i])
			low[i]=dfn[k];
	}
	if (dfn[i]==low[i]){
		bcnt++;
		do{
			k=stap[stop--];
			stack[k]=false;
			belong[k]=bcnt;
		}while (k!=i);
	}
}
