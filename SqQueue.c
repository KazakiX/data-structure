#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include "SqQueue.h"

SqQueue *Init_SqQueue(){
    SqQueue *q;
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
    return q;
}
int En_SqQueue(SqQueue *q,ElemType e){
    if((q->rear+1)%Maxsize==q->front) return 0;
    q->elem[q->rear]=e;
    q->rear=(q->rear+1)%Maxsize; return 1;
}
int De_SqQueue(SqQueue *q,ElemType *e){
    if(q->front==q->rear) return 0;
    *e=q->elem[q->front];
    q->front=(q->front+1)%Maxsize; return 1;
}
void Display_SqQueue(SqQueue *q){
    int i,Q;
    Q=q->front;
    for(i=q->front;i!=q->rear;i=(i+1)%Maxsize){printf("%d ",q->elem[i]);}
    printf("\n");
}

