#include<cstdio>
#include<algorithm>
//#include<iostream>
#define BOUND 5000001
using namespace std;

int N,K;
int A[BOUND];

int main(){
	scanf("%d%d",&N,&K);
	K = K-1;
	for(int i=0; i<N; i++)
		scanf("%d",&A[i]);

	nth_element(A,A+K,A+N);
	
	printf("%d\n",A[K]);	
}

