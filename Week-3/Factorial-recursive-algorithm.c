#include<stdio.h>
#include<stdlib.h>

int Factorial_Recursive(int);

void main(void)
{
	int N;

	printf("Enter an integer : ");
	scanf("%d",&N);
	printf("By iterative algorithm : %d! = %d\n",N,Factorial_Recursive(N));
}

int Factorial_Recursive(int N)
{
	if(N == 0)
		return 1;
	else
		return N * Factorial_Recursive(N - 1);
}
