#include <bits/stdc++.h>
using namespace std;
typedef int ElementType;
typedef struct{
	ElementType *array;
	int front;      //����λ��
	int rear;       //βָ��һ��λ��
	int length;     //����
	int capacity;   //������
}SeqQueue;

SeqQueue* createQueue(int capacity);
int full(SeqQueue *Q);
int push(SeqQueue *Q, ElementType x);
int pop(SeqQueue  *Q, ElementType  *x);
ElementType front(SeqQueue *Q);
int main()
{
    /*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
    return 0;
}
/*����ύ�Ĵ��뽫������ڴ˴����������Ŀ��Ҫ��ĺ����Ķ���*/
SeqQueue* createQueue(int capacity){
	SeqQueue* Q = (SeqQueue*)malloc(sizeof(SeqQueue));
	Q->array = (ElementType*)malloc(capacity * sizeof(ElementType));
	Q->front = Q->rear = 0;
	Q->length = 0;
	Q->capacity = capacity;
	return Q;
} 
int full(SeqQueue *Q){
	return Q->length == Q->capacity;
}
int push(SeqQueue *Q, ElementType x){
	if(Q->length == Q->capacity)	return 0;
	Q->array[++(Q->rear)] = x;
	return 1;
}
int pop(SeqQueue *Q, ElementType *x){
	if(Q->length == 0)	return 0;
	*x = Q->array[(Q->front)++];
	return 1;
}
ElementType front(SeqQueue *Q);{
	
}
