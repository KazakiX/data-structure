#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define OK 1
#define ERROR 0


typedef int Status;
typedef int ElemType;

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior,*next;
} DuLNode,*DuLinkList;

Status InitList(DuLinkList *L)
{
    /* 产生空的双向循环链表L */
    *L=(DuLinkList)malloc(sizeof(DuLNode));
    if(*L)
    {
        (*L)->next=(*L)->prior=*L;
        return OK;
    }
    else
        return ERROR;
}

Status GetElem(DuLinkList L,int i,ElemType *e)
{
    int j=1;
    DuLinkList p=L->next;
    while(p!=L&&j<i)
    {
        p=p->next;
        j++;
    }
    if(p==L||j>i)
        return ERROR;
    *e=p->data;
    return OK;
}

int ListLength(DuLinkList L)
 {
   int i=0;
   DuLinkList p=L->next;
   while(p!=L)
   {
     i++;
     p=p->next;
   }
   return i;
 }

DuLinkList GetElemP(DuLinkList L,int i)
 {
   int j;
   DuLinkList p=L;
   for(j=1;j<=i;j++)
     p=p->next;
   return p;
 }

Status ListInsert(DuLinkList L,int i,ElemType e)
{
    DuLinkList p,s;
    if(i<1||i>ListLength(L)+1)
        return ERROR;
    p=GetElemP(L,i-1);
    if(!p)
        return ERROR;
    s=(DuLinkList)malloc(sizeof(DuLNode));
    if(!s)
      return ERROR;
    s->data=e;
    s->prior=p;
    s->next=p->next;
    p->next->prior=s;
    p->next=s;
    return OK;
}

Status ListDelete(DuLinkList L,int i,ElemType *e)
{
    DuLinkList p;
    if(i<1||i>ListLength(L))
        return ERROR;
    p=GetElemP(L,i);
    if(!p)
        return ERROR;
    *e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    return OK;
}

void ListShow(DuLinkList L)
{
    DuLinkList p = L->next;
    int i = 0;
    while(p != L)
    {
        if(i++)
        {
            putchar(' ');
        }
        printf("%d", p->data);
        p = p->next;
    }
    putchar('\n');
}

int main()
{

    int s, i, e;
    DuLinkList L;
    InitList(&L);
    while(scanf("%d", &s) != EOF)
    {
        switch(s)
        {
        case 0:
            ListShow(L);
            break;
        case 1:
            scanf("%d%d", &i, &e);
            ListInsert(L, i, e);
            break;
        case 2:
            scanf("%d", &i);
            ListDelete(L, i, &e);
            break;
        }
    }

    return 0;
}
