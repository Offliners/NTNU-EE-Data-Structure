#include<stdio.h>
#include<stdlib.h>

#define MASIZE 15

void main(void)
{
	int square[MASIZE][MASIZE];
	int i,j,row,column;
	int count;
	int size;

	printf("Enter the size of the square : ");
	scanf("%d",&size);
	if((size < 1)||(size > MASIZE + 1))
	{
		fprintf(stderr,"Improper value of size.\n");
		exit(EXIT_FAILURE);
	}
	if(!(size % 2))
	{
		fprintf(stderr,"Error! Size is even.\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0;i < size;i++)
		for(j = 0;j < size;j++)
			square[i][j] = 0;
	square[0][(size - 1)/2] = 1;
	i = 0;
	j = (size - 1)/2;
	for(count = 2;count <= size*size;count++)
	{
		row = (i - 1 < 0) ? (size - 1) : (i - 1);
		column = (j - 1 < 0) ? (size - 1) : (j - 1);
		if(square[row][column])
			i = (++i) % size;
		else
		{
			i = row;
			j = column;
		}
		square[i][j] = count;
	}
	printf("Magic square of size %d x %d :\n\n",size,size);
	for(i = 0;i < size;i++)
	{
		for(j = 0; j < size;j++)
			printf("%5d", square[i][j]);
		printf("\n");
	}
}
