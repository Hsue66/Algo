#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	//for(int i=0; i<2*num-1; i++){
	for(int i=1; i<=num; i++){
		for(int j=num-i; j>0; j--)
			printf(" ");
		for(int j=0; j<2*i-1; j++)
			printf("*");
		printf("\n");
	}
}
