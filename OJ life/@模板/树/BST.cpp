#include <iostream>
using namespace std;

struct BNode{
	int data;
	BNode *l=NULL,*r=NULL;
}*tree=NULL;
int n,a,i;

void Creat(int a,BNode* &t);
//void PreOrder(BNode* &t);
void InOrder(BNode* &t);
//void PosOrder(BNode* &t);

int main()
{
	cin>>n;
	while (n--){
		cin>>a;
		Creat(a,tree);
	}
	InOrder(tree);
	return 0;
}

void Creat(int a,BNode* &t){
	if (!t){
		t=new BNode;
		t->data=a;
		return;
	}
	else
		if (a<t->data)
			Creat(a,t->l);
		else
			Creat(a,t->r);
	return;
}

void InOrder(BNode* &t){
	if (t){
		InOrder(t->l);
		cout<<t->data<<endl;
		InOrder(t->r);
	}
	return;
}
