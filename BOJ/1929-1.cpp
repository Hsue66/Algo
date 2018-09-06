#include<cstdio>
#include<iostream>
#define LIMIT 1000002

using namespace std;

int P[LIMIT];
int main(){
  int M, N;
  scanf("%d%d",&M,&N);
  fill_n(P,N+1,1);
  P[1] = 0;

  for(int n=2; n*n<=N; n++){
    if(P[n]){
      for(int i=n*n; i<=N; i=i+n)
        P[i] = 0;
    }
  }

  for(int i=M; i<=N; i++){
    if(P[i])
      printf("%d\n",i);
  }
}
