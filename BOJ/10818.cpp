#include<stdio.h>
#include<iostream>

using namespace std;


int main(){
	int testcase;
	scanf("%d",&testcase);
	int min = 1000000;
	int max = -1000000;
	while(testcase--){
		int num;
		scanf("%d",&num);
		
		if(min>num)
			min = num;
		if(max<num)
			max = num;
	}
	printf("%d %d\n",min,max);
}
