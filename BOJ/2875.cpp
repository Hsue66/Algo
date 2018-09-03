#include<cstdio>
#include<iostream>

using namespace std;

int N,M,K;
int MAX = 0;

int main(){
	scanf("%d%d%d",&N,&M,&K);

	while(N>=2 && M>=1 && M+N >= K+3){
		N -= 2;
		M -= 1;
		MAX += 1;
	}
	printf("%d\n",MAX);
}
