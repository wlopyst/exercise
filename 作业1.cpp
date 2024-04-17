#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int  coef;	//ϵ��(coefficient)
    int  exp;	//ָ��(exponent)
    struct Node *next;
} PolyNode, *PolyList;

void insertTail(PolyList L, int coef, int exp);
void printList(PolyList L);
void derivative(PolyList L);
void polyAdd(PolyList LA, PolyList LB,PolyList LC);
void polySub(PolyList LA, PolyList LB,PolyList LC);
int main()
{
    /*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
    return 0;
}
/*����ύ�Ĵ��뽫������ڴ˴����������Ŀ��Ҫ��ĺ����Ķ���*/
void insertTail(PolyList L, int coef, int exp){
	if(L == NULL){//�ձ� 
		PolyNode* p =(PolyNode*)malloc(sizeof(Node));
		if(p == NULL){
			cout << "failed" << endl;
		}
		p->coef = coef;
		p->exp = exp;
		L->next = p;
		p->next = NULL;
		return;
	}else{
		while(L->next != NULL){
			L = L->next;
		}
		PolyNode* p =(PolyNode*)malloc(sizeof(Node));
		p->coef = coef;
		p->exp = exp;
		L->next = p;
		p->next = NULL;
		return;
	}
}
void printList(PolyList L){
	if(L->next = NULL){
		cout << "0" << endl;
		return;
	}
	while(L->next != NULL){
		if(L->exp != 0){
			if(L->coef == 1 || L->coef == -1){
				//cout <<;
			}else{
				cout << L->coef;
			}
			if(L->exp == 1){
				cout << "x";
			}else{
				cout << "x^" << L->exp;
			}
		}else{
			cout << L->coef;
		}
	}
}
void derivative(PolyList L)
{
    PolyNode *p = L->next;
    PolyNode *pre = L;
    
    while (p != NULL)
    {
        if (p->exp == 0)
        {
            // ��������󵼺�ϵ��Ϊ0��ֱ��ɾ���ýڵ�
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            // �Էǳ����������
            p->coef *= p->exp;
            p->exp--;
            pre = p;
            p = p->next;
        }
    }
}
void polyAdd(PolyList LA, PolyList LB, PolyList LC)
{
    PolyNode *pa = LA->next;
    PolyNode *pb = LB->next;
    PolyNode *pc = LC;

    while (pa != NULL && pb != NULL)
    {
        if (pa->exp > pb->exp)
        {
            pc->next = (PolyNode *)malloc(sizeof(PolyNode));
            pc = pc->next;
            pc->coef = pa->coef;
            pc->exp = pa->exp;
            pa = pa->next;
        }
        else if (pa->exp < pb->exp)
        {
            pc->next = (PolyNode *)malloc(sizeof(PolyNode));
            pc = pc->next;
            pc->coef = pb->coef;
            pc->exp = pb->exp;
            pb = pb->next;
        }
        else
        {
            int sum = pa->coef + pb->coef;
            if (sum != 0)
            {
                pc->next = (PolyNode *)malloc(sizeof(PolyNode));
                pc = pc->next;
                pc->coef = sum;
                pc->exp = pa->exp;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }

    while (pa != NULL)
    {
        pc->next = (PolyNode *)malloc(sizeof(PolyNode));
        pc = pc->next;
        pc->coef = pa->coef;
        pc->exp = pa->exp;
        pa = pa->next;
    }

    while (pb != NULL)
    {
        pc->next = (PolyNode *)malloc(sizeof(PolyNode));
        pc = pc->next;
        pc->coef = pb->coef;
        pc->exp = pb->exp;
        pb = pb->next;
    }

    pc->next = NULL;
}
void polySub(PolyList LA, PolyList LB,PolyList LC){
	PolyNode* pa= LA->next;
	PolyNode* pb= LB->next;
	PolyNode* pc= LC->next;
	PolyNode* pre = LC;

	while(pa->next != NULL && pb->next != NULL){
		if(pa->exp > pb->exp){
			pc=(PolyNode*)malloc(sizeof(Node));
			pc->coef = pa->coef;
			pc->exp = pa->exp;
			pa = pa->next;
			pc = pc->next;
			pc = (PolyNode*)malloc(sizeof(Node));
			pc->coef = pb->coef;
			pc->exp = pb->exp;
			pb= pb->next;
			pre = pc;
			pc = pc->next;
		}else if(pa->exp == pb->exp){
			int sum = pa->coef + pb->coef;
			if(sum == 0){
				pa = pa->next;
				pb = pb->next;
			}else{
				pc =(PolyNode*)malloc(sizeof(Node));
				pc->coef = sum;
				pc->exp = pa->exp;
				pa = pa->next;
				pb = pb->next;
				pre = pc;
				pc = pc->next;
			}
		}else{
				pc=(PolyNode*)malloc(sizeof(Node));
				pc->coef = pb->coef;
				pc->exp = pb->exp;
				pa = pb->next;
				pc = pc->next;
				pc = (PolyNode*)malloc(sizeof(Node));
				pc->coef = pa->coef;
				pc->exp = pa->exp;
				pa= pa->next;
				pre = pc;
				pc = pc->next;
			}
	}
}
