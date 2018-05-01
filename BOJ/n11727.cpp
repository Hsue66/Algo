#include<cstdio>
//#include<iostream>
#define BOUND 1001
#define MAX 10007

using namespace std;

int N;
int M[BOUND];

int main(){
	scanf("%d",&N);
	M[0] = 1;
	M[1] = 1;

	for(int i=2; i<= N; i++)
		M[i] = (M[i-1] + 2*M[i-2]) % MAX;
	
	printf("%d\n",M[N]);
}
