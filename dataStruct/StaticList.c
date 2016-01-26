#include <stdio.h>
#define ERROR 0
#define OK 1

#define  MAXSIZE 1000
typedef  int  ElemType ;

typedef struct  
{
	ElemType  data ;
	int   cur  ;
}Component ,StaticLinkList[MAXSIZE];


int InitStaticList(StaticLinkList  list)
{
	int i ;
	for (i = 0; i < MAXSIZE -1; ++i)
	{
		list[i].cur = i+1 ;
	}

	list[MAXSIZE-1].cur = 0 ;

	return  OK ;
}

int malloc_SLL(StaticLinkList L)
{
	int i = L[0].cur ;

	if (i)
	{
		L[0].cur = L[i].cur ;
	}

	return  i ;
}


int InsertList(StaticLinkList L,int i , ElemType e )
{
	int j ,k,l;
	k = MAXSIZE-1 ;
	j = malloc_SLL(L) ;


	if(i<1 || i>j-1)
		return  ERROR ;

	if ( j)
	{
		L[j].data = e ;
		for(l =1;l<i;i++)
			k = L[k] .cur ;

		L[j].cur = L[k].cur;
		L[k].cur = j ;
		return  OK ;
	}

	return ERROR ;

}

int  int main(int argc, char const *argv[])
{
	
	return 0;
}