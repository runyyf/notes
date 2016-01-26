#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ERROR 0
#define OK    1

//如果定义了结构体指针但是没有分配地址区域就直接赋值会导致段错误
//解决的方法 1.动态分配一块内存 2.指向一个已经存在的空间 。

typedef struct Node
{
	int date ;
	struct Node *next ;

}Node;

typedef struct Node* LinkList ;
typedef int Status;


Status GetELem(LinkList L,int i,int *e)
{
	int j;

	if (i<1)
	{
		return ERROR ;
	}

	LinkList p;
	p = L;
	j=1;

	while( p && j<i)
	{
		p = p->next;
		j++;
	}

	if (!p)  //i大于单链表的实际长度
	{
		return ERROR ;		
	}

	*e = p->date ;
	return OK ;

}



Status InsertList(LinkList L,int i,int e)
{
	if (i<1)
	{
		return ERROR ;
	}

	LinkList p = NULL ;
	LinkList s = NULL ;
	p = L;
	int j = 1 ;

	while(p && j<(i-1))
	{
		p = p->next ;
		j++;
	}

	if (!p)
		return ERROR ;

	s = (LinkList)malloc(sizeof(Node));  //分配内存
	s->next = p->next ;
	p->next = s ;
	s->date = e ;


	int ret = 0;
	int value = 0 ;
	ret = GetELem(L,i,&value);
	printf("GetELem(),ret = [%d],value = [%d]\n",ret,value);

	return OK ;

}

Status DeleteList(LinkList L,int i,int *e)
{
	if (i<1)
	{
		return ERROR ;
	}

	LinkList p,s;
	p = L;
	int j = 1;

	while(p && j<(i-1))
	{
		p = p->next ;
		j++ ;
	}	

	s = (LinkList)malloc(sizeof(Node));

	s = p->next ;
	p->next = s->next ;
	*e = s->date ;

	free(s);

	int ret = 0;
	int value = 0 ;
	ret = GetELem(L,i,&value);
	printf("GetELem(),ret = [%d],value = [%d]\n",ret,value);

	return OK ;

}

void  CreatListTail(LinkList L,int n)
{
	LinkList p,r;
	int i ;

	srand(time(0));
	L = (LinkList)malloc(sizeof(Node));
	r = L ;

	for (i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->date = rand()%100+1 ;
		r->next = p;
		r = p ;
	}

	r->next = NULL ;

}


void ClearList(LinkList L)
{

	LinkList p ,q ;
	p = (L)->next ;

	while(p)
	{
		printf("1111\n");
		q=p->next ;
		printf("2222\n");
		free(p);
		printf("3333\n");
		p = q ;

	}
	(L)->next = NULL ;

} 

int main()
{

	Node a,b,c,d;

	a.date = 1 ;
	a.next = &b ;

	b.date = 2 ;
	b.next = &c ;

	c.date = 3 ;
	c.next = &d; 

	d.date = 4 ;

	int ret = 0 ;
	int value = 0 ;

	ret = GetELem(&a,2,&value);
	printf("GetELem() ,ret = [%d],value = [%d]\n",ret,value);

	ret = InsertList(&a,2,10);
	printf("InsertList(), ret = [%d]\n",ret);

	ret = DeleteList(&a,2,&value);
	printf("DeleteList() ,ret = [%d],value = [%d]\n",ret,value);

#if 0
	Node *p ;
	p =&a ;
	ClearList(p);
	ret = GetELem(&a,1,&value);
	printf("GetELem() ,ret = [%d],value = [%d]\n",ret,value);
#endif
	
	return 0;
}