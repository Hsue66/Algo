#include<cstdio>
#include<iostream>
#define BOUND 1001
using namespace std;

int N;
int P[BOUND];
int M[BOUND];

void sell(){
	for(int i=1; i<N; i++){
		int before = 0;
		M[i] = P[i];
		for(int j = i; j*2 >= i; j--)
			before = max(M[i-j]+M[j],before);
		M[i] = before;
	}
	printf("%d\n",M[N-1]);
}

int main(){
	scanf("%d",&N);
	N = N+1;
	M[0] = P[0] = 0; 
	for(int i=1; i<N; i++){
		scanf("%d",&P[i]);
	}

	sell();
}
