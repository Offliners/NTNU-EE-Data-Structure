#include<stdio.h>
#include<stdlib.h>

typedef struct list_node *list_pointer;

struct list_node
{
	int data;
	list_pointer link;
};

list_pointer create2();

void main()
{
	list_pointer list1;

	list1 = create2();
	printf("List 1 :\n");
	printf("Data = %d\n\n",list1->data);
	printf("List 2 :\n");
	printf("Data = %d\n\n",(list1->link)->data);
}

list_pointer create2()
{
	list_pointer first, second;

	first = (list_pointer)malloc(sizeof(*first));
	second = (list_pointer)malloc(sizeof(*second));
	second->link = NULL;
	second->data = 20;
	first ->link = second;
	first->data = 10;

	return first;
}
