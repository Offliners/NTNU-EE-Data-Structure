#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 3

void mult(int a[][MAXSIZE],int b[][MAXSIZE],int c[][MAXSIZE],int,int);

void main(void)
{
	int a[3][MAXSIZE],b[3][MAXSIZE],c[3][MAXSIZE];
	int i,j;

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
	mult(a,b,c,3,3);
	printf("\n");
	printf("The result :\n");
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
}

void mult(int a[][MAXSIZE],int b[][MAXSIZE],int c[][MAXSIZE],int rows,int cols)
{
	int i,j,k;
	int count = 0;

	for(i = 0; i < rows;i++)
	{
		for(j = 0;j < cols;j++)
		{		
			c[i][j] = 0;
			for(k = 0;k < cols;k++)
				c[i][j] += a[i][k]*b[k][j];
		}
	}
}
