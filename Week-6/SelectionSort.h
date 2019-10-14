#include<stdlib.h>
#include<math.h>

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int list[],int n)
{
	int i,j,min,temp;

	for(i = 0; i < n;i++)
	{
		min = i;

		for(j = i + 1;j < n;j++)
			if(list[j] < list[min])
				min = j;
		swap(&list[i],&list[min]);
	}
}
