#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTree;

int getDepth(BTree rt);
int getLeafNum(BTree rt);
void leafNode(BTree rt);
int getNum(BTree rt);
int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
int getDepth(BTree rt){
	int HL, HR, MaxH;
	
	if(rt){
		HL = getDepth(rt->lchild);
		HR = getDepth(rt->rchild);
		MaxH = HL > HR ? HL : HR;
		return (MaxH + 1); 
	}
	else return 0;
}
int getLeafNum(BTree rt) {
  // 如果树为空，则没有叶子节点
  if (rt == NULL) {
    return 0;
  }

  // 如果是叶子节点，则返回 1
  if (rt->lchild == NULL && rt->rchild == NULL) {
    return 1;
  }

  // 递归计算左右子树的叶子节点数量并返回总和
  return getLeafNum(rt->lchild) + getLeafNum(rt->rchild);
}
void leafNode(BTree rt){
	if(rt){
		if(!rt->lchild && !rt->rchild){
			cout << rt->data;
		}
		leafNode(rt->lchild);
		leafNode(rt->rchild);
	}
}
int getNum(BTree rt){
	int cnt;
	if(rt){
		cnt++;
		getNum(rt->lchild);
		getNum(rt->rchild);
		return cnt;
	}else{
		return 0;
	}
}
