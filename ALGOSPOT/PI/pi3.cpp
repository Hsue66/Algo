#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<string>

//char numbers[10001];
int cache[10001];
int size;

int search(char[] subnumbers, int first)
{
	if(first == size)
		return 0;

	if(cache[first]!= -1)
		return cache[first];
/*
	int ret = 987654321;
	for(int i=2; i<5; i++)
		if(first+i <= size)
			ret = min(ret,getMinValue(subnumbers
*/
	printf("%s",subnumbers.substr(2,4));

}


int main()
{
	int testcase;
	scanf("%d",&testcase);

	for(int i=0; i<testcase; i++)
	{
		scanf("%s",numbers);
		size = strlen(numbers);

		memset(cache,-1,sizeof(int)*10001);
//		int total = search(numbers,0);

		printf("%d",size);
		printf("%s",numbers);
	}
}
