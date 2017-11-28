#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	while(num--){
		for(int j=0; j<=num; j++){
			printf("*");
		}
		printf("\n");
	}
}
