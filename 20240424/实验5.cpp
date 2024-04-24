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
    /*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
    return 0;
}
/*����ύ�Ĵ��뽫������ڴ˴����������Ŀ��Ҫ��ĺ����Ķ���*/
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
  // �����Ϊ�գ�����������κβ���
  if (bt == NULL) {
    return;
  }

  // �ݹ�������������������
  destroyTree(bt->lchild);
  destroyTree(bt->rchild);

  // ɾ����ǰ�ڵ�
  delete bt;
}
