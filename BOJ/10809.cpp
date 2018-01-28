#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	char alpha=0;
	int arr[26];
	fill_n(arr,26,-1);

	int count = 0;
	while(alpha != 10 && scanf("%c",&alpha)==1){
		if(arr[alpha-'a'] == -1)
			arr[alpha-'a'] = count;
		count++;
	}

	printf("%d",arr[0]);
	for(int i=1; i<26; i++)
		printf(" %d",arr[i]);
	printf("\n");
}
