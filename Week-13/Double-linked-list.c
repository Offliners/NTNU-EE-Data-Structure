#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;

struct listNode
{
	listPointer Llink;
	int data;
	listPointer Rlink;
};

void doubleListInsert(listPointer *first, listPointer node, int new_node_data);
void listPrint(listPointer first);
listPointer listSearch(listPointer first, int data);
void inverseListPrint(listPointer first);
void doubleListDelete(listPointer *first, listPointer node, listPointer deleted);

void main()
{
	listPointer first = NULL, node = NULL;
	int num, i, data;

	printf("Enter the number of data item : ");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("Enter the data item No.%d : ",i);
		scanf("%d",&data);
		doubleListInsert(&first,node,data);
		if(i == 1)
			node = first;
		else
			node = node->Rlink;
	}
	listPrint(first);
	printf("Enter the data to be found : ");
	scanf("%d",&data);
	node = listSearch(first,data);
	printf("Enter the data to be inserted after the data %d : ",data);
	scanf("%d",&data);
	doubleListInsert(&first,node,data);
	listPrint(first);
	printf("Enter the data to be deleted : ", data);
	scanf("%d",&data);
	node = listSearch(first,data);
	doubleListDelete(&first,node->Llink,node);
	listPrint(first);
	inverseListPrint(first);
}

void doubleListInsert(listPointer *first, listPointer node, int new_node_data)
{
	listPointer temp = (listPointer)malloc(sizeof(*temp));

	temp->data = new_node_data;
	if(!(*first))
	{
		temp->Rlink = NULL;
		temp->Llink = NULL;
		*first = temp;
	}
	else if(node->Rlink == NULL)
	{
		temp->Llink = node;
		temp->Rlink = node->Rlink;
		node->Rlink = temp;
	}
	else
	{
		temp->Llink = node;
		temp->Rlink = node->Rlink;
		(node->Rlink)->Llink = temp;
		node->Rlink = temp;
	}
}

void listPrint(listPointer first)
{
	printf("The linked list contains :\n");
	for(;first != NULL;first = first->Rlink)
		printf("%4d",first->data);
	printf("\n");
}

listPointer listSearch(listPointer first, int data)
{
	for(;first != NULL;first = first->Rlink)
		if(first->data == data)
			return first;
	return NULL;
}

void inverseListPrint(listPointer first)
{
	printf("The inversed linked list contains :\n");
	for(;first->Rlink != NULL;first = first->Rlink);
	for(;first != NULL;first = first->Llink)
		printf("%4d",first->data);
	printf("\n");
}

void doubleListDelete(listPointer *first, listPointer node, listPointer deleted)
{
	if(node)
	{
		deleted->Llink->Rlink = deleted->Rlink;
		if(deleted->Rlink != NULL)
			deleted->Rlink->Llink = deleted->Llink;
	}
	else
	{
		deleted = *first;
		*first = (*first)->Rlink;
		(*first)->Llink = NULL;
	}
	free(deleted);
}
