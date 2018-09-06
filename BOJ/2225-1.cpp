#include<cstdio>
//#include<iostream>
#define LIMIT 201
#define DIV 1000000000

using namespace std;

int M[LIMIT][LIMIT];
int main(){
  int N,K;
  scanf("%d%d",&N, &K );
  for(int i=0; i<N+1; i++)
    M[1][i] = 1;
  for(int i=0; i<K+1; i++)
    M[i][0] = 1;

  for(int k=2; k<K+1; k++){
    for(int n=1; n<N+1; n++)
      M[k][n] = (M[k][n-1] + M[k-1][n])%DIV;
  }
  printf("%d\n",M[K][N]);
}
