#include<stdio.h>
#include <stdlib.h>


int main()
{
	int a, n;
	int i =0, j=0;
	int temp =0;
	long int *list;

	scanf("%d",&a);

	for(i=0; i<a ; i++)
	{
		scanf("%d",&n);
		list = (long int*)malloc(sizeof(long int)*n+1);

	
		if( n != 0)
		{
			list[0] = 0;
			list[1] = 1;
			for(j=0; j<n-1; j++)
			{
				list[j+2] = list[j] + list[j+1];
			}
			printf("%li %li\n",list[n-1],list[n]);

		}

		else
			printf("1 0\n");

	}


	free(list);
	return 0;
}
