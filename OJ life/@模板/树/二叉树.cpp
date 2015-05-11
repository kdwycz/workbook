//==========================================定义头部
#include <iostream>
using namespace std;
struct BiTNode{
 char data;
 struct BiTNode *lchild, *rchild;//左右孩子
};
BiTNode *T;
void CreateBiTree(BiTNode* &T);
void Inorder(BiTNode* &T);
void PreOrderTraverse(BiTNode* &T);
void Posorder(BiTNode* &T);
//===========================================主函数
int main(){
cout<<"创建一颗树，其中A->Z字符代表树的数据，用“#”表示空树:"<<endl;
  CreateBiTree(T);
cout<<"先序递归遍历："<<endl;
PreOrderTraverse(T);
cout<<endl;
cout<<"中序递归遍历："<<endl;
  Inorder(T);
cout<<endl;
cout<<"后序递归遍历："<<endl;
        Posorder(T);
cout<<endl;
  return 1;}
//=============================================先序递归创建二叉树树
void CreateBiTree(BiTNode* &T){
 //按先序输入二叉树中结点的值（一个字符），空格字符代表空树，
 //构造二叉树表表示二叉树T。
 char ch;
 if((ch=getchar())=='#')T=NULL;//其中getchar（）为逐个读入标准库函数
 else{
  T=new BiTNode;//产生新的子树
  T->data=ch;//由getchar（）逐个读入来
  CreateBiTree(T->lchild);//递归创建左子树
  CreateBiTree(T->rchild);//递归创建右子树
 }
}//CreateTree
//===============================================先序递归遍历二叉树
void PreOrderTraverse(BiTNode* &T){
 //先序递归遍历二叉树
 if(T){//当结点不为空的时候执行
  cout<<T->data;
  PreOrderTraverse(T->lchild);//
  PreOrderTraverse(T->rchild);
 }
 else cout<<"";
}//PreOrderTraverse
//================================================中序遍历二叉树
void Inorder(BiTNode* &T){//中序递归遍历二叉树
 if(T){//bt=null退层
  Inorder(T->lchild);//中序遍历左子树
  cout<<T->data;//访问参数
  Inorder(T->rchild);//中序遍历右子树
 }
 else cout<<"";
 }//Inorder
//=================================================后序递归遍历二叉树
void Posorder(BiTNode* &T){
 if(T){
  Posorder(T->lchild);//后序递归遍历左子树
  Posorder(T->rchild);//后序递归遍历右子树
  cout<<T->data;//访问根结点
 }
 else cout<<"";
}
//=================================================
