#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int key;
}element;

typedef struct stack *stack_pointer;

struct stack
{
	element data;
	stack_pointer link;
}; 

void push(stack_pointer *top, element item);
element pop(stack_pointer *top);
void listStack(stack_pointer top);

void main()
{
	stack_pointer top = NULL;
	int num, i;
	element item;

	printf("Enter the number of data items to be pushed into the stack : ");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("\nEnter the data item No.%d : ",i);
		scanf("%d",&item.key);
		push(&top,item);
		printf("The data item %d has been added.\n",item.key);
	}
	printf("\nEnter the number of data item to be popped from the stack : ");
	scanf("%d",&num);
	printf("\n");
	for(i = 1;i<=num;i++)
	{
		item = pop(&top);
		printf("The data item No.%d (with key value = %d) popped!\n",i,item.key);
	}
	printf("The current data items in the stack include :\n");
	listStack(top);
}

void push(stack_pointer *top, element item)
{
	stack_pointer temp = (stack_pointer)malloc(sizeof(*temp));
	if(temp == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	temp->data = item;
	temp->link = *top;
	*top = temp;
}

element pop(stack_pointer *top)
{
	stack_pointer temp = *top;
	element item;

	if(temp == NULL)
	{
		printf("The stack is empty!\n");
		exit(1);
	}
	item = temp->data;
	*top = temp->link;
	free(temp);

	return item;
}

void listStack(stack_pointer top)
{
	printf("The linked stack contains :\n");
	for(;top != NULL;top = top->link)
		printf("%4d",(top->data).key);
	printf("\n");
}
