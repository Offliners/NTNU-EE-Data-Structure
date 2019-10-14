#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 3

void transpose(int a[][MAXSIZE],int,int);
void swap(int *,int *);

void main(void)
{
	int a[3][MAXSIZE];
	int i,j;

	printf("Enter a matrix :\n");
	for(i = 0;i < 3;i++)
	{
		printf("The %d row : ",i + 1);
		for(j = 0;j < 3;j++)
			scanf("%d",&a[i][j]);
	}
	transpose(a,3,3);
	printf("\n");
	printf("The result :\n");
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

void transpose(int a[][MAXSIZE],int rows,int cols)
{
	int i,j;

	for(i = 0; i < rows - 1;i++)
	{
		for(j = i + 1;j < cols;j++)
			swap(&a[i][j],&a[j][i]);
	}
}

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
