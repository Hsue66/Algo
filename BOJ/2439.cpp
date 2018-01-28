#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	for(int i=1; i<=num; i++){
		for(int j=1; j<=num; j++){
			if(j<=num-i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}
