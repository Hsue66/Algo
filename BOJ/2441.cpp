#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(j<i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}
