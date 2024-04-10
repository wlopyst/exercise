#include <bits/stdc++.h>
using namespace std;
typedef int ElementType;
typedef struct{
	ElementType *array;
	int front;      //队首位置
	int rear;       //尾指下一个位置
	int length;     //长度
	int capacity;   //总容量
}SeqQueue;

SeqQueue* createQueue(int capacity);
int full(SeqQueue *Q);
int push(SeqQueue *Q, ElementType x);
int pop(SeqQueue  *Q, ElementType  *x);
ElementType front(SeqQueue *Q);
int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
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
