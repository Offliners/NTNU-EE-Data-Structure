#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 3

int add(int a[][MAXSIZE],int b[][MAXSIZE],int c[][MAXSIZE],int,int);

void main(void)
{
	int a[3][MAXSIZE],b[3][MAXSIZE],c[3][MAXSIZE];
	int i,j,count;

	printf("Enter the first matrix :\n");
	for(i = 0;i < 3;i++)
	{
		printf("The %d row : ",i + 1);
		for(j = 0;j < 3;j++)
			scanf("%d",&a[i][j]);
	}
	printf("Enter the second matrix :\n");
	for(i = 0;i < 3;i++)
	{
		printf("The %d row : ",i + 1);
		for(j = 0;j < 3;j++)
			scanf("%d",&b[i][j]);
	}
	count = add(a,b,c,3,3);
	printf("\n");
	printf("The result :\n");
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	printf("It takes %d steps.\n",count);
}

int add(int a[][MAXSIZE],int b[][MAXSIZE],int c[][MAXSIZE],int rows,int cols)
{
	int i,j;
	int count = 0;

	for(i = 0; i < rows;i++)
	{
		count++;
		for(j = 0;j < cols;j++)
		{
			count++;
			c[i][j] = a[i][j] + b[i][j];
			count++;
		}
		count++;
	}

	count++;
	return count;
}
