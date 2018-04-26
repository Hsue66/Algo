#include<cstdio>
#include<cmath>
//#include<iostream>
#define MAX 1000001
using namespace std;

int N;
int check[MAX];

void findPrime(int before){
	int len = sqrt(N)+1;
	for(int i=2; i<len; i++){
		int now = before/i;
		while(now*i <= N){
			if(now != 1)
				check[now*i] = 1;
			now++;
		}
	}
	check[1] = 1;
	check[2] = 1;
}


int main(){
	int testcase;
	int max = 0;
	while(1){
		scanf("%d",&N);

		if(N == 0)
			break;
		
		if(max < N){
			findPrime(max);
			max = N;
		}
		
		int flag = 1;
		for(int i=3; i<=N/2; i++){
			if(check[i] == 0 && check[N-i] == 0){
				flag = 0;
				printf("%d = %d + %d\n",N,i,N-i);
				break;
			}
		}

		if(flag)
			printf("Goldbach's conjecture is wrong.\n");

	}
}
