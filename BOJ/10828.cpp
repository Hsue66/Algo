#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int Stack[10000];
int top = 1;

int main(){
	int lineOforder;
	scanf("%d%*c",&lineOforder);
	
	Stack[0]=-1;

	while(lineOforder--){
		/*
		printf("STACK: ");
		for(int i=0; i<top; i++)
			printf("%d ",Stack[i]);
		printf("\n");
*/
		char order[5];
		scanf("%s%*c",order);
		if(strcmp(order,"push")==0){
			int value;
			scanf("%d",&value);
			Stack[top]= value;
			top++;
		}
		else if(strcmp(order,"pop")==0){
			if(top != 0)
				top--;
			printf("%d\n",Stack[top]);
			if(top == 0)
				top++;
		}			
		else if(strcmp(order,"size")==0){
			printf("%d\n",top-1);
		}
		else if(strcmp(order,"empty")==0){
			if(top == 1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if(strcmp(order,"top")==0){
				printf("%d\n",Stack[top-1]);
		}
	}
}
