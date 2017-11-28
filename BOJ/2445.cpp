#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	int cnt = 1;
	for(int i=1; i<=2*num-1; i++){
		for(int j=1; j<=2*num; j++){
			if(j<=cnt || 2*num-cnt <j)
				printf("*");
			else
				printf(" ");
		}
		if(num>i)
			cnt++;
		else
			cnt--;
		printf("\n");
	}
}
