#include<stdio.h>
#include<time.h>
#include"SelectionSort.h"

#define MAXSIZE 1001

void main(void)
{
	int i,n,step = 10;
	int a[MAXSIZE];
	double duration;
	clock_t start;

	printf("   n      time\n");
	for(n = 10;n <= 1000; n+= step)
	{
		for(i = 0;i < n;i++)
			a[i] = n - 1;
		start = clock();
		sort(a,n);
		duration = (double)(clock() - start) / CLOCKS_PER_SEC;
		printf("%4d      %f\n",n,duration);
		if(n == 100)
			step = 100;
	}
}
