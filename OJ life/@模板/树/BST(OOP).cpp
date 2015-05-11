#include<iostream>
using namespace std;

template <class T>
class TreeNode{
	public:
		TreeNode():lson(NULL),rson(NULL),freq(1){}
		T data;
		unsigned int freq;
		TreeNode* lson;
		TreeNode* rson;
};

template <class T>
class BST{
    private:
        TreeNode<T>* root;//根节点
        void insertpri(TreeNode<T>* &node,T x);//插入
        TreeNode<T>* findpri(TreeNode<T>* node,T x);//查找
        void insubtree(TreeNode<T>* node);//中序遍历
        void Deletepri(TreeNode<T>* &node,T x);//删除
    public:
        BST():root(NULL){}
        void insert(T x);//插入接口
        TreeNode<T>* find(T x);//查找接口
        void Delete(T x);//删除接口
        void traversal();//遍历接口
};

template <class T>
void BST<T>::insertpri(TreeNode<T>* &node,T x){
    if(node==NULL)//如果节点为空,就在此节点处加入x信息
    {
        node=new TreeNode<T>();
        node->data=x;
        return;
    }
    if(node->data>x)//如果x小于节点的值,就继续在节点的左子树中插入x
        insertpri(node->lson,x);
    else
		if(node->data<x)//如果x大于节点的值,就继续在节点的右子树中插入x
        	insertpri(node->rson,x);
    	else ++(node->freq);//如果相等,就把频率加1
}

//插入接口
template <class T>
void BST<T>::insert(T x){
    insertpri(root,x);
}

//查找
template <class T>
TreeNode<T>* BST<T>::findpri(TreeNode<T>* node,T x)
{
    if(node==NULL)//如果节点为空说明没找到,返回NULL
    {
        return NULL;
    }
    if(node->data>x)//如果x小于节点的值,就继续在节点的左子树中查找x
    {
        return findpri(node->lson,x);
    }
    else if(node->data<x)//如果x大于节点的值,就继续在节点的左子树中查找x
    {
        return findpri(node->rson,x);
    }
    else return node;//如果相等,就找到了此节点
}

//查找接口
template <class T>
TreeNode<T>* BST<T>::find(T x){
    return findpri(root,x);
}

//删除
template <class T>
void BST<T>::Deletepri(TreeNode<T>* &node,T x)
{
    if(node==NULL) return ;//没有找到值是x的节点
    if(x < node->data)
    Deletepri(node->lson,x);//如果x小于节点的值,就继续在节点的左子树中删除x
    else if(x > node->data)
    Deletepri(node->rson,x);//如果x大于节点的值,就继续在节点的右子树中删除x
    else//如果相等,此节点就是要删除的节点
    {
        if(node->lson&&node->rson)//此节点有两个儿子
        {
            TreeNode<T>* temp=node->rson;//temp指向节点的右儿子
            while(temp->lson!=NULL) temp=temp->lson;//找到右子树中值最小的节点
            //把右子树中最小节点的值赋值给本节点
            node->data=temp->data;
            node->freq=temp->freq;
            Deletepri(node->rson,temp->data);//删除右子树中最小值的节点
        }
        else//此节点有1个或0个儿子
        {
            TreeNode<T>* temp=node;
            if(node->lson==NULL)//有右儿子或者没有儿子
            node=node->rson;
            else if(node->rson==NULL)//有左儿子
            node=node->lson;
            delete(temp);
        }
    }
    return;
}

//删除接口
template <class T>
void BST<T>::Delete(T x)
{
    Deletepri(root,x);
}

//中序遍历函数
template <class T>
void BST<T>::insubtree(TreeNode<T>* node)
{
    if(node==NULL) return;
    insubtree(node->lson);//先遍历左子树
    cout<<node->data<<" ";//输出根节点
    insubtree(node->rson);//再遍历右子树
}

//中序遍历接口
template <class T>
void BST<T>::traversal()
{
    insubtree(root);
}

int main()
{
	BST<int> tr;
	int n,i,a;
	cin>>n;
	while (n--){
		cin>>a;
		tr.insert(a);
	}
	tr.traversal();
	return 0;
}
