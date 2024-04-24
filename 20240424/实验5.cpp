#include<bits/stdc++.h>
using namespace std;

typedef int ElementType1;
typedef struct QNode
{
	ElementType1 *array;
	int front;
	int rear;
}Queue;

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTree;

BTree createTree(char s[]);
void preOrder(BTree bt);
void inOrder(BTree bt);
void postOrder(BTree bt);
void layerOrder(BTree bt);
void printTree(BTree bt);
void destroyTree(BTree bt);
int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
BTree createTree(char s[]){
	
}
void preOrder(BTree bt){
	if(bt){
		cout << bt->data;
		preOrder(bt->lchild);
		preOrder(bt->rchild);
	}
}
void inOrder(BTree bt){
	if(bt){
		inOrder(bt->lchild);
		cout << bt->data;
		inOrder(bt->rchild);
	}
}
void postOrder(BTree bt){
	if(bt){
		postOrder(bt->lchild);
		postOrder(bt->rchild);
		cout << bt->data;
	}
}
void layerOrder(BTree bt){
	Queue Q;
	BTree T;
	
}
void printTree(BTree bt){
	
}
void destroyTree(BTree bt) {
  // 如果树为空，则无需进行任何操作
  if (bt == NULL) {
    return;
  }

  // 递归销毁左子树和右子树
  destroyTree(bt->lchild);
  destroyTree(bt->rchild);

  // 删除当前节点
  delete bt;
}
