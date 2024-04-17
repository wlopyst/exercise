#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int  coef;	//系数(coefficient)
    int  exp;	//指数(exponent)
    struct Node *next;
} PolyNode, *PolyList;

void insertTail(PolyList L, int coef, int exp);
void printList(PolyList L);
void derivative(PolyList L);
void polyAdd(PolyList LA, PolyList LB,PolyList LC);
void polySub(PolyList LA, PolyList LB,PolyList LC);
int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
void insertTail(PolyList L, int coef, int exp){
	if(L == NULL){//空表 
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
            // 处理常数项，求导后系数为0，直接删除该节点
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            // 对非常数项进行求导
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
