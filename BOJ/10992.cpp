#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	int blank = num;
	for(int i=1; i<=num; i++,blank--){
		for(int j=1; j<blank; j++)
			printf(" ");
		if(i==num){
			for(int j=1; j<=2*num-1; j++)
				printf("*");
		}
		else{
			for(int j=1; j<=2*i-1; j++){
				if(j==1 || j==2*i-1)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}
