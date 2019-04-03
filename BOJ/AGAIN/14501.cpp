#include<iostream>
#include<cstdio>

using namespace std;

int N,MAX;
int P[15],T[15],M[15];

void calc(int idx, int before){
  //in
  if(T[idx]+idx <= N && before+P[idx] > M[idx]){
    M[idx] = before + P[idx];
    calc(idx+T[idx], M[idx]);
  }
  // not in
  //if(M[idx+1] < before)
  if(idx+1 < N)
    calc(idx+1,before);
}

int main(){
  scanf("%d",&N );
  for(int i=0; i<N; i++)
    scanf("%d%d",&T[i],&P[i] );

  fill_n(M,N,-1);
  calc(0,0);

  MAX = 0;
  for(int i=0; i<N; i++)
    MAX = max(MAX,M[i]);

  printf("%d\n",MAX );
}
