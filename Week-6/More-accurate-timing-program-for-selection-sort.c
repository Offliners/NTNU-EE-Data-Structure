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
    long repetitions;

    printf("   n      repetitions      time\n");
    for(n = 0;n <=1000;n += step)
    {
    	repetitions = 0;
    	start = clock();
    	do
    	{
    		repetitions++;
    		for(i = 0;i < n;i++)
    			a[i] = n - i;
    		sort(a,n);
    	}while(clock() - start < 1000);
        duration = (double)(clock() - start) / CLOCKS_PER_SEC;
        duration /= repetitions;
        printf("%4d   %14d    %f\n",n,repetitions,duration);
        if(n == 100)
       	    step = 100;
	}
}
