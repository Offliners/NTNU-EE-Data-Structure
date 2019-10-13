#include<stdio.h>
#include<stdlib.h>

int Factorial_Iterative(int);

void main(void)
{
	int N;

	printf("Enter an integer : ");
	scanf("%d",&N);
	printf("By iterative algorithm : %d! = %d\n",N,Factorial_Iterative(N));
}

int Factorial_Iterative(int N)
{
	int i,fac = 1;

	if(N == 0)
		return 1;
	else
	{
		for(i = N;i >= 1;i--)
			fac *= i;
		return fac;
	}
}
