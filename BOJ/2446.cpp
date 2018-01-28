#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	int cnt = 0;
	for(int i=1; i<=2*num-1; i++){
		for(int j=1; j<=2*num-1-cnt; j++){
			if(j<=cnt)
				printf(" ");
			else
				printf("*");
		}
		if(num>i)
			cnt++;
		else
			cnt--;
		printf("\n");
	}
}
