#include<stdio.h>
#include<stdlib.h>

#define MAXTERM 101

typedef struct
{
	int col;
	int row;
	int value;
}term;

void main()
{
	term a[MAXTERM];
	int i;

	a[0].row = 6;
	a[0].col = 6;
	a[0].value = 8;
	a[1].row = 0;
	a[1].col = 0;
	a[1].value = 15;
	a[2].row = 0;
	a[2].col = 3;
	a[2].value = 22;
	a[3].row = 0;
	a[3].col = 5;
	a[3].value = -15;
	a[4].row = 1;
	a[4].col = 1;
	a[4].value = 11;
	a[5].row = 1;
	a[5].col = 2;
	a[5].value = 3;
	a[6].row = 2;
	a[6].col = 3;
	a[6].value = -6;
	a[7].row = 4;
	a[7].col = 0;
	a[7].value = 91;
	a[8].row = 5;
	a[8].col = 2;
	a[8].value = 28;
	printf("Output a:\n");
	for(i = 0;i <= 8;i++)
	{
		printf("(%d, %d, %d)",a[i].row,a[i].col,a[i].value);
		printf("\n");
	}
}
