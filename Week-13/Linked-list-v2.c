#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;

struct listNode
{
	int data;
	listPointer link;
};

void listInsert(listPointer *first, listPointer x, int data);
void listPrint(listPointer first);
listPointer listSearch(listPointer first, int data);
listPointer listSearchPrev(listPointer first, int data);
void listDelete(listPointer *first, listPointer trail, listPointer x);

void main()
{
	listPointer first = NULL, x = NULL, trail = NULL;
	int num, i, data;

	printf("Enter the number of data item : ");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("Enter the data item No.%d : ",i);
		scanf("%d",&data);
		listInsert(&first,x,data);
		if(i == 1)
			x = first;
		else
			x = x->link;
	}
	listPrint(first);
	x = listSearch(first,20);
	listInsert(&first,x,25);
	listPrint(first);
	trail = listSearchPrev(first,25);
	listDelete(&first,trail,trail->link);
	listPrint(first);
	trail = listSearchPrev(first,50);
	listDelete(&first,trail,trail->link);
	listPrint(first);
}

void listInsert(listPointer *first, listPointer x, int data)
{
	listPointer temp;

	temp = (listPointer)malloc(sizeof(*temp));
	if(temp == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	else
	{
		temp->data = data;
		if(*first != NULL)
		{
			temp->link = x->link;
			x->link = temp;
		}
		else
		{
			temp->link = NULL;
			*first = temp;
		}
	}
}

void listPrint(listPointer first)
{
	printf("The linked list contains :\n");
	for(;first != NULL;first = first->link)
		printf("%4d",first->data);
	printf("\n");	
}

listPointer listSearch(listPointer first, int data)
{
	for(;first != NULL;first = first->link)
		if(first->data == data)
			return first;
	return NULL;
}

listPointer listSearchPrev(listPointer first, int data)
{
	for(;first->link != NULL;first = first->link)
		if((first->link)->data == data)
			return first;
	return NULL;
}

void listDelete(listPointer *first, listPointer trail, listPointer x)
{
	if(trail)
		trail->link = x->link;
	else
	{
		x = *first;
		*first = (*first)->link;
	}
	free(x);
}
