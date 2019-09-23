#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 101

void Sort(int [],int);
void Swap(int *,int *);

void main(void)
{
	int list[MAXSIZE];
	int n,i;

	printf("Enter the number of integers : ");
	scanf("%d",&n);
	if(n < 1 || n > MAXSIZE)
	{
		fprintf(stderr,"Error input!\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0;i < n;i++)
	{
		list[i] = rand() % 1000;
		printf("%d ",list[i]);
	}
	printf("\nSorted Array :\n");
	Sort(list,n);
	for(i = 0;i < n;i++)
		printf("%d ",list[i]);
}

void Sort(int list[],int n)
{
	int i,j,min;

	for(i = 0;i < n;i++)
	{
		min = i;

		for(j = i + 1;j < n;j++)
		{
			if(list[j] < list[min])
				min = j;
		}
		Swap(&list[i],&list[min]);
	}
}

void Swap(int *a,int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
