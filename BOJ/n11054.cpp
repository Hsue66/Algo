#include<cstdio>
#include<iostream>
#define BOUND 1002

using namespace std;

int N;
int A[BOUND],Cnt[BOUND],Cnt2[BOUND];
int MAX = 0;

void find(){
	for(int n=1; n<N; n++){
		for(int i=0; i<n; i++){
			if(A[i] < A[n])
				Cnt[n] = max(Cnt[n],Cnt[i]+1);
			if(A[N-i] < A[N-n])
				Cnt2[N-n] = max(Cnt2[N-n],Cnt2[N-i]+1);
		}
	}

	
	for(int i=1; i<N; i++){
		int sum =  Cnt[i] + Cnt2[i];
		if(MAX < sum)
			MAX = sum;
	}
}

int main(){
	scanf("%d",&N);
	N = N+1;
	A[0] = Cnt[0] = Cnt2[N] = 0;
	for(int i=1; i<N; i++)
		scanf("%d",&A[i]);

	find();

	printf("%d\n",MAX-1);
}
