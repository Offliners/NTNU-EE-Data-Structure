#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef struct 
{
	int key;
}element;

void addq(element *queue,int front,int *rear,element item);
void queueEmpty();
void queueFull();
void outputQueue(element *queue,int front,int rear);
element deleteq(element *queue,int *front,int rear);

void main()
{
	element queue[MAXSIZE];
	int rear = 0;
	int front = 0;
	int num,i;
	element item;

	printf("Enter the number (at most %d) of data itemsto be added into the queue : ",MAXSIZE);
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("\nEnter the data item No.%d : ",i);
		scanf("%d",&item.key);
		addq(queue,front,&rear,item);
		printf("The data item %d has been added.\n",item.key);
	}
	printf("\nEnter the number of data items to be deleted from the queue : ");
	scanf("%d",&num);
	printf("\n");
	for(i = 1;i <= num;i++)
	{
		item = deleteq(queue,&front,rear);
		printf("The data item No.%d (with key value = %d) deleted!\n",i,item.key);		
	}
	printf("The current data items in the queue include :\n");
	outputQueue(queue,front,rear);
	printf("\n(Again) Enter the number of data items to be added into the queue : ");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("\nEnter the data item No.%d : ",i);
		scanf("%d",&item.key);
		addq(queue,front,&rear,item);
		printf("The data item %d has been added.\n",item.key);
	}
	printf("The current data items in the queue include :\n");
	outputQueue(queue,front,rear);
}

void addq(element *queue,int front,int *rear,element item)
{
	*rear = (*rear + 1) % MAXSIZE;
	if(front == *rear)
		queueFull();
	else
		queue[*rear] = item;
}

void queueEmpty()
{
	printf("Queue empty!\n");
	exit(1);
}

void queueFull()
{
	printf("Queue full!\n");
	exit(1);
}

void outputQueue(element *queue,int front,int rear)
{
	int i;
	if(front == rear)
		queueEmpty();
	else
	{
		if(front < rear)
			for(i = (front + 1);i <= rear;i++)
				printf("%d ",queue[i].key);
		else
		{
			for(i = (front + 1);i <= MAXSIZE - 1;i++)
				printf("[%d]%d",i,queue[i].key);
			for(i = 0;i <= rear;i++)
				printf("[%d]%d",i,queue[i].key);
		}
	}
}

element deleteq(element *queue,int *front,int rear)
{
	if(*front == rear)
		queueEmpty();
	else
	{
		*front = (*front + 1) % MAXSIZE;
		return queue[*front];
	}
}
