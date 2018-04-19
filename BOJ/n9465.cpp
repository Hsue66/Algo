#include<cstdio>
#include<algorithm>
//#include<iostream>
#define MAX 100001

using namespace std;

int N;
int S[2][MAX];
int T[3][MAX];

void select(){
	for(int i=1; i<N; i++){
		// 2
		T[2][i] = max(T[2][i-1],T[1][i-1]);
		T[2][i] = max(T[2][i],T[0][i-1]);

		// 0
		T[0][i] = T[2][i-1] + S[0][i];
		T[0][i] = max(T[0][i], T[1][i-1] + S[0][i]);

		// 1
		T[1][i] = T[2][i-1] + S[1][i];
		T[1][i] = max(T[1][i], T[0][i-1] + S[1][i]);

		//cout<<T[2][i]<<" "<<T[0][i]<<" "<<T[1][i]<<endl;
	}

	int Max;
	Max = max(T[2][N-1],T[1][N-1]);
	Max = max(Max,T[0][N-1]);

	printf("%d\n",Max);
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&N);
		for(int i=0; i<2; i++){
			for(int j=0; j<N; j++)
				scanf("%d",&S[i][j]);
		}

		T[0][0] = S[0][0];
		T[1][0] = S[1][0];
		T[2][0] = 0;

		select();
	}
}
