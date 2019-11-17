#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 101

typedef struct 
{
	int col;
	int row;
	int value;
} term;

void fast_transpose(term a[], term b[]);

void main()
{
	term a[MAX_COL], b[MAX_COL];
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
	for (i = 0; i <= 8; i++)
	{
		printf("(%d, %d, %d)", a[i].row, a[i].col, a[i].value);
		printf("\n");
	}
	
	fast_transpose(a, b);
	
	printf("Output b:\n");
	for (i = 0; i <= 8; i++)
	{
		printf("(%d, %d, %d)", b[i].row, b[i].col, b[i].value);
		printf("\n");
	}
}

void fast_transpose(term a[], term b[])
{
    int row_terms[MAX_COL] = {0}, starting_pos[MAX_COL];
    int i, j, num_cols = a[0].col, num_terms = a[0].value;
    int k;
    
	b[0].row = num_cols; 
	b[0].col = a[0].row;
    b[0].value = num_terms;
    
    if (num_terms > 0) 
	{ 
    	for(i = 1; i <= num_terms; i++)
        	row_terms[a[i].col]++;
        starting_pos[0] = 1;
        for(i = 1; i < num_cols; i++)
    		starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        for(i = 1; i <= num_terms; i++) 
		{
        	j = starting_pos[a[i].col];
        	starting_pos[a[i].col]++;

            b[j].row = a[i].col;
			b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}               

