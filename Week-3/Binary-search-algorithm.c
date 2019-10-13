#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 101

void sort(int [],int);
void swap(int *,int *);
int binarySearch(int [],int,int,int);
int compare(int,int);

void main(void)
{
	int i,n;
	int list[MAXSIZE];
	int searchNum,found;

	printf("Enter the number of numbers to generate : ");
	scanf("%d",&n);
	if((n < 1)||(n > MAXSIZE))
	{
		fprintf(stderr,"Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0;i < n;i++)
	{
		list[i] = rand() % 1000;
		printf("%d ",list[i]);
	}
	sort(list,n);
	printf("\nSorted array :\n");
	for(i = 0;i < n;i++)
		printf("%d ",list[i]);
	printf("\n");
	printf("Enter the number you want to search : ");
	scanf("%d",&searchNum);
	if((found = binarySearch(list,searchNum,0,n-1)) == -1)
		printf("%d cannot be found\n",searchNum);
	else
		printf("%d can be found in the position : %d\n",searchNum,found);

}

void sort(int list[],int n)
{
	int i,j,min,temp;

	for(i = 0;i < n;i++)
	{
		min = i;

		for(j = i + 1;j < n;j++)
			if(list[j] < list[min])
				min = j;
		swap(&list[i],&list[min]);
	}
}

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int binarySearch(int list[],int searchNum,int left,int right)
{
	int middle;

	while(left <= right)
	{
		middle = (left + right) / 2;
		switch(compare(list[middle],searchNum))
		{
			case -1:
				left = middle + 1;
				break;
			case 0:
				return middle;
				break;
			case 1:
				right = middle - 1;
				break;
		}
	}
	return -1;
}

int compare(int x,int y)
{
	if(x < y)
		return -1;
	else if(x == y)
		return 0;
	else
		return 1;
}
