#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode, *LinkList;

Status ListEmpty(LinkList l){
  if(!(l->next))
    return OK;
  return ERROR;
}

Status GetElem(LinkList l,int n,int *e){
  LinkList p = l->next;
  int j = 1;
  while(p && j < n){
    p = p->next;
    j++;
  }
  if(!p||j>n)
    return ERROR;
  *e = p->data;
  return OK;
}

Status ListDelete(LinkList l,int n,int *e){
  LinkList p = l,q;
  int j = 0;
  q = (LinkList)malloc(sizeof(LNode));
  while (p&&j < n-1){
    p = p->next;
    j++;
  }
  if(!p||j>n-1)
    return ERROR;
  q = p->next;
  p->next = q->next;
  *e = q->data;
  free(q);
  return OK;
}

Status ListInsert(LinkList l, int n, int e){
  LinkList p = l,s;
  int j = 0;
  while(p&&j <n-1){
    p = p->next;
    j++;
  }
  if(j>n-1||!p)
    return ERROR;

  s = (LinkList)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

void Insert(LinkList l,int e){
  LinkList s;
  s = (LinkList)malloc(sizeof(LNode));
  s->data = e;
  s->next = l->next;
  l->next = s;
}

void PrintList(LinkList l){
  LinkList p = l->next;
  while(p){
    printf("%d ",p->data);
    p = p->next;
  }
  printf("\n");
}

main(){
  int n,i,m,a,e;
  int num[N+10];
  LinkList l;
  char str[N+10];
  scanf("%d",&n);
  l = (LinkList)malloc(sizeof(LNode));
  l->next = NULL;
  for(i=1;i<=n;i++){
    scanf("%d",&num[i]);
    Insert(l,num[i]);
  }
  scanf("%d",&m);
  getchar();
  while(scanf("%s",str)!=EOF){
    if(!strcmp(str,"get")){
      scanf("%d",&a);
      if(GetElem(l,a,&e))
        printf("%d\n",e);
      else
        printf("get fail\n");
    }
    if(!strcmp(str,"delete")){
      scanf("%d",&a);
      if(ListDelete(l,a,&e))
        printf("delete OK\n");
      else
      printf("delete fail\n");
    }
    if(!strcmp(str,"insert")){
      scanf("%d%d",&a,&e);
      if(ListInsert(l,a,e))
        printf("insert OK\n");
      else
      printf("insert fail\n");
    }
    if(!strcmp(str,"show")){
      if(ListEmpty(l)){
        printf("Link list is empty\n");
      }
      else
        PrintList(l);
    }
    getchar();
  }
  return 0;
}
