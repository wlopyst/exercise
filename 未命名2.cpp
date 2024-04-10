#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTree;

BTree createTree(char s[]);

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
	BTree* T = (BTree*)malloc(sizeof(BTNode));
	BTree* p;
	for(int i = 0; i <strlen(s);i++){
		switch(s[i]){
			case '(':
				p = T;
				T = T->lchild;
				break;
			case ',':
				T = p->rchild;
				break;
			case ')':
				T = p;
				break;
			default:
				T->data = s[i];
		}
			
		
	}
}
