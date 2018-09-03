#include<cstdio>
//#include<iostream>

using namespace std;

int A[11] = {0};
int Input,N;
int Cnt = 0;

int main(){
	scanf("%d%d",&N,&Input);
	for(int i=0; i<N; i++)
		scanf("%d",&A[i]);

	for(int i=N-1; i >= 0; i--){
		Cnt += (Input / A[i]);
		Input =  (Input % A[i]);
	}
	printf("%d\n",Cnt);
}
