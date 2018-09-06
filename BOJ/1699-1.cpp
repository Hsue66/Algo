#include<cstdio>
#include<iostream>
#include<cmath>
#define LIMIT 100002
using namespace std;

int P[LIMIT];

int main(){
  int N;
  scanf("%d",&N);
  fill_n(P,N+1,LIMIT);
  P[0] = 0;
  P[1] = 1;
  P[2] = 2;
  P[3] = 3;

  for(int i= 4; i<N+1; i++){
    for(int t = sqrt(i); t>0; t--)
      P[i] = min(1+P[i-(t*t)] , P[i]);
  }
  printf("%d\n",P[N] );
}
