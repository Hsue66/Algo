#include <cstdio>
#include <cstring>

int main(){
	char alpha=0;
	int arr[26] = {0};
	while(alpha != 10 && scanf("%c",&alpha)==1){
		arr[alpha-'a']++;
	}
	printf("%d",arr[0]);
	for(int i=1; i<26; i++)
		printf(" %d",arr[i]);
	printf("\n");
}
