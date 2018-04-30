#include<cstdio>
#include<algorithm>
//#include<iostream>
#define BOUND 5000001
using namespace std;

int N,K;
int A[BOUND];

void search(int start, int end){
	int idx = start;
	int val = A[end-1];
	for(int i=start; i<end-1; i++){
		if(A[i] < val){
			swap(A[idx],A[i]);
			idx++;
		}
	}
	swap(A[idx],A[end-1]);

	if(K==idx)
		printf("%d\n",A[K]);
	else if(K <idx)
		search(start,idx);
	else
		search(idx+1,end);
}	

int main(){
	scanf("%d%d",&N,&K);
	K = K-1;
	for(int i=0; i<N; i++)
		scanf("%d",&A[i]);
	
	search(0,N);
}
