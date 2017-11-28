#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	for(int i=1; i<=2*num-1; i++){
		int left = i%num;
		int limit = num - left;
		if(i>=num)
			limit = left;
		
		for(int j=limit; j>0; j--)
			printf(" ");
		for(int j=0; j<2*(num-limit)-1; j++)
			printf("*");
		printf("\n");
	}
}
