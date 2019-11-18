#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct
{
	int key;
} element;

void push(element *stack,int *top,element item);
element pop(element *stack,int *top);
void stack_full();
void stack_empty();
void output_stack(element *stack, int top);

void main()
{
	element stack[MAXSIZE];
	int top = -1;
	int num,i;
	element item;
	
	printf("Enter the number of data items to be pushed into the stack : ");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("\nEnter the data item No.%d : ",i);
		scanf("%d",&item.key);
		push(stack,&top,item);
		printf("The data item %d has been added.\n",item.key);
	}
	printf("\nEnter the number of data items to be popped from the stack : ");
	scanf("%d",&num);
	printf("\n");
	for(i = 1;i <= num;i++)
	{
		item = pop(stack,&top);
		printf("The data item No.%d (with key value = %d) popped!\n",i,item.key);
	}
	printf("The current data items in the stack include :\n");
	output_stack(stack,top);
}

void push(element *stack,int *top,element item)
{
	if(*top >= MAXSIZE - 1)
		stack_full();
	else
	{
		(*top)++;
		stack[(*top)] = item;
	}	
}

element pop(element *stack,int *top)
{
	if(*top == -1)
		stack_empty();
	else
		return stack[(*top)--];
}

void stack_full()
{
	printf("Stack full!\n");
	exit(1);
}

void stack_empty()
{
	printf("Stack empty!\n");
	exit(1);
}

void output_stack(element *stack, int top)
{
	int i;
	
	if(top == -1)
		stack_empty();
	else
		for(i = 0;i <= top;i++)
			printf("%d ",stack[i].key);
}
