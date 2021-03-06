#include<stdio.h>
#include<stdlib.h>

float Float_Sum(float [],int,int *);
float R_Float_Sum(float [],int,int *);

void main(void)
{
	float F[10],float_sum;
	int n,i,count = 0;

	printf("Enter the number of numbers to be added : ");
	scanf("%d",&n);
	printf("Enter %d real numbers :\n",n);
	for(i = 0;i < n;i++)
		scanf("%f",&F[i]);
	float_sum =Float_Sum(F,n,&count);
	printf("[Iterative] The number of step = %d\n",count);
	for(i = 0;i < n;i++)
	{
		if(i < n - 1)
			printf("%.2f + ",F[i]);
		else
			printf("%.2f = ",F[i]);
	} 
	printf("%.2f\n",float_sum);

	count = 0;
	float_sum =R_Float_Sum(F,n,&count);
	printf("[Recursive] The number of step = %d\n",count);
	for(i = 0;i < n;i++)
	{
		if(i < n - 1)
			printf("%.2f + ",F[i]);
		else
			printf("%.2f = ",F[i]);
	} 
	printf("%.2f\n",float_sum);
}

float Float_Sum(float list[],int n,int *count)
{
	float tempSum = 0; (*count)++;
	int i;

	for(i = 0;i < n;i++)
	{
		(*count)++;
		tempSum += list[i]; (*count)++;
	}
	(*count)++;

	(*count)++;
	return tempSum;
}

float R_Float_Sum(float list[],int n,int *count)
{
	(*count)++;
	if(n)
	{
		(*count)++;
		return (R_Float_Sum(list,n - 1,&(*count)) + list[n - 1]);
	}

	(*count)++;
	return 0.0;
}
