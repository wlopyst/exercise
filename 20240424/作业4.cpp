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
    /*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
    return 0;
}
/*����ύ�Ĵ��뽫������ڴ˴����������Ŀ��Ҫ��ĺ����Ķ���*/
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
  // �����Ϊ�գ���û��Ҷ�ӽڵ�
  if (rt == NULL) {
    return 0;
  }

  // �����Ҷ�ӽڵ㣬�򷵻� 1
  if (rt->lchild == NULL && rt->rchild == NULL) {
    return 1;
  }

  // �ݹ��������������Ҷ�ӽڵ������������ܺ�
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
