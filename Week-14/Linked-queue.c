#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	int key;	
}element;

typedef struct queue *queue_pointer;

struct queue
{
	element data;
	queue_pointer link;
};

void addq(queue_pointer *front, queue_pointer *rear, element item);
element deleteq(queue_pointer *front);
void listQueue(queue_pointer front);

void main()
{
	queue_pointer front = NULL, rear = NULL;
	int num, i;
	element item;

	printf("Enter the number of data items to be pushed into the queue : ");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("\nEnter the data item No.%d : ",i);
		scanf("%d",&item.key);
		addq(&front, &rear, item);
		printf("The data item %d has been added.\n",item.key);
	}
	printf("\nEnter the number of data items to be deleted from the queue : ");
	scanf("%d",&num);
	printf("\n");
	for(i = 1;i <= num;i++)
	{
		item = deleteq(&front);
		printf("The data item No.%d (with key value = %d) deleted!\n",i,item.key);
	}
	printf("The current data items in the queue include :\n");
	listQueue(front);
}

void addq(queue_pointer *front, queue_pointer *rear, element item)
{
	queue_pointer temp = (queue_pointer)malloc(sizeof(*temp));
	if(temp == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	temp->data = item;
	temp->link = NULL;
	if(*front)
		(*rear)->link = temp;
	else
		*front = temp;
	*rear = temp;
}

element deleteq(queue_pointer *front)
{
	queue_pointer temp = *front;
	element item;

	if(temp == NULL)
	{
		printf("The queue is empty!\n");
		exit(1);
	}
	item = temp->data;
	*front = temp->link;
	free(temp);

	return item;
}

void listQueue(queue_pointer front)
{
	printf("The linked queue contains :\n");
	for(;front != NULL;front = front->link)
		printf("%4d",(front->data).key);
	printf("\n");
}
