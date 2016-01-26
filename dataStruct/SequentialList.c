#include<stdio.h>
#define ERROR 0
#define OK   1
#define MAXNUM 20

typedef int ElemType ;
typedef struct  
{
	ElemType data[MAXNUM];
	int length ;	
}SqList;


int	GetElem(SqList l,int i,ElemType* e)
{
	if (l.length == 0 || i<1|| l.length<i)
		return ERROR ;

	*e = l.data[i-1];

	return OK ;

} 

int ListInsert(SqList* l,int i,ElemType e)
{
	int k=0;
	if (l->length == MAXNUM)
	{
		return ERROR ;
	}

	if (i<1||i>l->length+1)
	{
		return ERROR;
	}

	if (i<=l->length)
	{
		for (k=l->length-1; k < l->length-1; k++)
		{
			l->data[k+1] = l->data[k];
		}
	}

	l->data[i-1]= e ;
	l->length++;

	return OK ;
}

int ListDelete(SqList* Lp,int i,ElemType *e)
{
	int count = 0 ;
	if (Lp->length == 0)
	{
		return ERROR ;
	}
	if (i<1 || i>Lp->length)
	{
		return ERROR;
	}

	*e = Lp->data[i-1];
	for (count = i-1 ;count<Lp->length-1;count++)
	{
		Lp->data[count] = Lp->data[count+1];
	}

	Lp->length--;
	return OK;
}


int main()
{

	SqList a = {0};
	int ret = 0 ;
	int value = 0 ;

	a.length = 10 ;
	ret = GetElem(a,7,&value);
	printf("111 ...ret = [%d] ,a.data[6] = [%d]\n"
		,ret,a.data[6]);

	SqList* p ;
	p = &a ;

	ret = ListInsert(p,7,99);
	printf("222 ...ret = [%d] ,p->data[6] = [%d]\n"
		,ret,p->data[6]);

	a.length = 20 ;
	ret = ListDelete(p,7,&value);
	printf("333 ...ret = [%d] ,p->data[6] = [%d],value = [%d],p->length=[%d]\n"
		,ret,p->data[6],value,p->length);


	return 0 ;
}