#include<stdio.h>
#include<stdlib.h>

#define MAXTERM 100

typedef struct 
{
	float coef;
	int exp;
}polynomial;

polynomial terms[MAXTERM];
int avail = 0;

void polyAdd(int start_a,int end_a,int start_b,int end_b,int *start_d,int *end_d);
void attach(float coefficient,int exponent);
int compare(int exp_a,int exp_b);

void main()
{
	int startd,finishd,i;
	
	terms[0].coef = 3;
	terms[0].exp = 3;
	terms[1].coef = 5;
	terms[1].exp = 2;
	terms[2].coef = 5;
	terms[2].exp = 0;
	printf("Poly 1 : ");
	for(i = 0;i <= 2;i++)
		printf("(%.0f, %d)",terms[i].coef,terms[i].exp);
	printf("\n");
	terms[3].coef = -5;
	terms[3].exp = 2;
	terms[4].coef = 7;
	terms[4].exp = 1;
	terms[5].coef = 3;
	terms[5].exp = 0;
	printf("Poly 2 : ");
	for(i = 3;i <= 5;i++)
		printf("(%.0f, %d)",terms[i].coef,terms[i].exp);
	printf("\n");
	polyAdd(0,2,3,5,&startd,&finishd);
	printf("After adding Poly 1 and Poly 2 :\n");
	for(i = startd;i <= finishd;i++)
		printf("(%.0f, %d)",terms[i].coef,terms[i].exp);
}

void polyAdd(int start_a,int end_a,int start_b,int end_b,int *start_d,int *end_d)
{
	float coefficient;
	*start_d = avail;

	while((start_a <= end_a)&&(start_b <= end_b))
	{
		switch(compare(terms[start_a].exp,terms[start_b].exp))
		{
			case -1:
				attach(terms[start_b].coef,terms[start_b].exp);
				start_b++;
				break;
			case 0:
				coefficient = terms[start_a].coef + terms[start_b].coef;
				if(coefficient)
					attach(coefficient,terms[start_a].exp);
				start_a++;
				start_b++;
				break;
			case 1:
				attach(terms[start_a].coef,terms[start_a].exp);
				start_a++;
				break;
		}
	}
	for(;start_a <= end_a;start_a++)
		attach(terms[start_a].coef,terms[start_a].exp);
	for(;start_b <= end_b;start_b++)
		attach(terms[start_b].coef,terms[start_b].exp);
	*end_d = avail - 1;
}

void attach(float coefficient,int exponent)
{
	if(avail > MAXTERM)
	{
		fprintf(stderr,"Too many terms in the polynomial!\n");
		exit(1);
	}
	terms[avail].coef = coefficient;
	terms[avail].exp = exponent;
	avail++;
}

int compare(int exp_a,int exp_b)
{
	if(exp_a < exp_b)
		return -1;
	else if(exp_a == exp_b)
		return 0;
	else
		return 1;
}
