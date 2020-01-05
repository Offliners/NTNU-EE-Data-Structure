#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef struct
{
	int key;
} element;

void add(element *queue,int *rear,element item);
void queue_full();
void queue_empty();
void output_queue(element *queue,int front,int rear);
element delete(element *queue,int *front,int rear);

void main()
{
	element queue[MAXSIZE];
	
	int rear = -1;
	int front = -1;
	int num,i;
	element item;
	
	printf("Enter the number of data items to be added into the queue : ");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("\nEnter the data item No.%d : ",i);
		scanf("%d",&item.key);
		add(queue,&rear,item);
		printf("The data item %d has been added.\n",item.key);
	}
	printf("\nEnter the number of data items to be deleted from the queue : ");
	scanf("%d",&num);
	printf("\n");
	for(i = 1;i <= num;i++)
	{
		item = delete(queue,&front,rear);
		printf("The data item No.%d (with key value = %d) deleted!\n",i,item.key);
	}
	printf("The current data items in the queue include :\n");
	output_queue(queue,front,rear);
	printf("\n\n(Again) Enter the number of data items to be added into the queue : ");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		printf("\nEnter the data item No.%d : ",i);
		scanf("%d",&item.key);
		add(queue,&rear,item);
		printf("The data item %d has been added.\n",item.key);
	}
	printf("The current data items in the queue include :\n");
	output_queue(queue,front,rear);
}

void add(element *queue,int *rear,element item)
{
	if(*rear == MAXSIZE - 1)
		queue_full();
	else
		queue[++(*rear)] = item;	
}

void queue_full()
{
	printf("Queue full!\n");
	exit(1);	
}

void queue_empty()
{
	printf("Queue empty!\n");
	exit(1);
}

void output_queue(element *queue,int front,int rear)
{
	int i;
	
	if(front == rear)
		queue_empty();
	else
		for(i = (++front);i <= rear;i++)
			printf("%d ",queue[i].key);	
}

element delete(element *queue,int *front,int rear)
{
	if(*front == rear)
		queue_empty();
	else
		return queue[++(*front)];
}
