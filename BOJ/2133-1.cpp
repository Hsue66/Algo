#include<cstdio>
#include<iostream>
#define BOUND 31

using namespace std;

int N;
int M[BOUND];

int main(){
	scanf("%d",&N);
	M[1] = 3;

	int num;
	if(N%2 != 0)
		num = 0;
	else{
		for(int i=4; i<= N; i= i+2){
			M[i/2] = 3*M[(i-2)/2];
			for(int t = i-4; t>0; t=t-2)
				M[i/2] += 2*M[t/2];
			M[i/2] += 2;
		}
		num = M[N/2];
	}
	
	for(int i=0; i<N; i++)
		cout<<M[i]<<" ";

	printf("%d\n",num);
}


