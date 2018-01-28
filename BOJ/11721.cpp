#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	char temp[100];
	while(scanf("%10s",temp)==1){
		printf("%s\n",temp);
	}
	/*
	scanf("%s",temp);

	int i= 0;
	while(temp[i]!='\0'){
		printf("%c",temp[i]);
		if((i+1)%10 == 0)
			printf("\n");
		i++;
	}
	printf("\n");
	*/
}
