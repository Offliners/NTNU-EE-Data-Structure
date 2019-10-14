#include<stdio.h>
#include<stdlib.h>

void print1(int *,int);

void main(void)
{
	int one[] = {1,2,3,4,5};

	print1(one,5);
}

void print1(int *ptr,int rows)
{
	int i;

	printf(" Address Contents\n");
	for(i = 0;i < rows;i++)
		printf("%8u%5d\n",ptr+i,*(ptr + i));
	        // printf("%8u%5d\n", &ptr[i], ptr[i]);
	printf("\n");
}
