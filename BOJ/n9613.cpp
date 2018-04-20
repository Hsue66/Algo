#include<cstdio>
//#include<iostream>

using namespace std;

long long sum;
int N;
int Num[101];

int getGCD(int a, int b){
	do{
		int big = a;
		int small = b;
		if(a < b){
			small = a;
			big = b;
		}
		
		a = big - small;
		b = small;
	}while(a != 0);
	
	return b;
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&N);
		for(int i=0; i<N; i++)
			scanf("%d",&Num[i]);
		sum = 0;

		for(int i=0; i<N-1; i++){
			for(int j=i+1; j<N; j++)
				sum += getGCD(Num[i],Num[j]);
		}
		
		printf("%lld\n",sum);
	}
}
