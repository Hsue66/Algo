#include<stdio.h>
#include<stdlib.h>

int main()
{
	int  n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	
	int *arr = malloc(sizeof(int)*n);
	for( int i =0 ; i<n; i++;)  	
		scanf("%d",arr[i]);

	for( int i =0 ; i<n; i++;)  	
		printf("%d",arr[i];	
	free(arr);
	return 0;
}
