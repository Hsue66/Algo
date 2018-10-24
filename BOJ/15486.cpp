#include<iostream>
#include<cstdio>
#define LIMIT 1500002
using namespace std;

int N;
int T[LIMIT];
int P[LIMIT];
int D[LIMIT];

int main(){
  scanf("%d",&N);
  for(int i=1; i<=N; i++)
    scanf("%d%d",&T[i],&P[i]);

  D[0] = 0;
  for(int i=1; i<=N; i++){
    if(1 <= i+T[i]-1 && i+T[i]-1 <= N)
      D[i+T[i]-1] = max(D[i-1]+P[i],D[i+T[i]-1]);
    D[i] = max(D[i-1],D[i]);
  }
  printf("%d\n",D[N]);
}
