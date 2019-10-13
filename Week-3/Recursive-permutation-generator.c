#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 101

void Perm(char [],int,int);
void swap(char *,char *);

void main(void)
{
	char list[MAXSIZE];
	int n,i;

	printf("Enter the number of characters for a string : ");
	scanf("%d",&n);
	if((n < 1)||(n >MAXSIZE))
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	printf("\nEnter %d characters : ",n);
	scanf("%s",list);
	printf("All character permutations for the string are :\n");
	Perm(list,0,n-1);
}

void Perm(char list[],int i,int n)
{
	int j,temp;

	if(i == n)
	{
		for(j = 0;j <= n;j++)
			printf("%c",list[j]);
		printf("    ");
	}
	else
	{
		for(j = i;j <= n;j++)
		{
			swap(&list[i],&list[j]);
			Perm(list,i + 1,n);
			swap(&list[i],&list[j]);
		}
	}
}

void swap(char *x,char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}
