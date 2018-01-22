#include<stdio.h>
#include<iostream>

using namespace std;

int num[1001] = {0};

int tile(int n){
	if(n==1)
		return num[0];
	else if(n==2)
		return num[1];
	else{
		if(num[n]==0)
			num[n-1] = (tile(n-2)+tile(n-1))%10007;
		return num[n-1];
	}
}

int main(){
	int width;	
	scanf("%d",&width);
	num[0] = 1;
	num[1] = 2;

	printf("%d\n",tile(width));	
}
