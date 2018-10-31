//#include<iostream>
#include<cstdio>
#define LIMIT 1000001

using namespace std;

long long D[101][101][101];
int N,M,K;

void find(int n, int m, int k){
  if(n == 0){
    if(k == 0)
      D[n][m][k] = 1;
    else D[n][m][k] = 0;
  }else{
    long long temp = 0;

    // 0개
    if(D[n-1][m][k] == -1)
      find(n-1,m,k);
    temp += D[n-1][m][k];

    // 1개
    if(k-1 >= 0 && m-1 >= 0){
      if(D[n-1][m-1][k-1] == -1)
        find(n-1,m-1,k-1);
      temp += D[n-1][m-1][k-1]*m;
    }
    if(k-2 >= 0 && m-1 >= 0 && n-2 >= 0){
      if(D[n-2][m-1][k-2] == -1)
        find(n-2,m-1,k-2);
      temp += D[n-2][m-1][k-2]*m*(n-1);
    }

    // 2개
    if(k-2 >= 0 && m-2 >= 0){
      if(D[n-1][m-2][k-2] == -1)
        find(n-1,m-2,k-2);
      temp += D[n-1][m-2][k-2]*m*(m-1)/2;
    }
    D[n][m][k] = temp%LIMIT;
  }
}

int main(){
  for(int i=0; i<101; i++){
    for(int j=0; j<101; j++){
      for(int k=0; k<101; k++)
        D[i][j][k] = -1;
    }
  }
  scanf("%d%d%d",&N,&M,&K);
  find(N,M,K);
  printf("%lld\n",D[N][M][K]);
}
