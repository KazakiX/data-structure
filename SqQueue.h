#pragma c9x on
#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int ElemType;
#define Maxsize 10

typedef struct SqQueue{
    ElemType elem[Maxsize];
    int front,rear;
}SqQueue;
SqQueue *Init_SqQueue();
int En_SqQueue(SqQueue *q,ElemType e);
int De_SqQueue(SqQueue *q,ElemType *e);
void Display_SqQueue(SqQueue *q);

#endif
