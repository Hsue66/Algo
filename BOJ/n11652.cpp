#include<cstdio>
#include<algorithm>
//#include<iostream>
#define BOUND 1000001

using namespace std;

long long A[BOUND];
int N;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%lld",&A[i]);

	sort(A,A+N);

	int max = 0, cnt = 1;
	long long idx = 0;
	for(int i=1; i<N; i++){
		if(A[i] == A[i-1])
			cnt++;
		else{
			if(max < cnt){
				max = cnt;
				idx = A[i-1];
			}
			cnt = 1;
		}
	}
	if(max < cnt){
		max = cnt;
		idx = A[N-1];
	}

	printf("%lld\n",idx);
}

