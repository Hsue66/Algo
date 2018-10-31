//#include<iostream>
#include<cstdio>
#define LIMIT 1000000007

using namespace std;

int N,M,P;
long long D[101][101][101];

void find(int i, int x, int y){
  if(P == i){
    if(y == 0)
      D[i][x][y] = 1;
    else
      D[i][x][y] = 0;
  }else{
    long long temp = 0;
    if(y > 0){
      if(D[i+1][x+1][y-1] == -1)
        find(i+1,x+1,y-1);
      temp = D[i+1][x+1][y-1] * y;
    }

    if(x-M > 0){
      if(D[i+1][x][y] == -1)
        find(i+1,x,y);
      temp = temp + (D[i+1][x][y] * (x-M));
    }
    D[i][x][y] = temp % LIMIT;
  }
}

int main(){
  for(int i=0; i<101; i++){
    for(int j=0; j<101; j++){
      for(int k=0; k<101; k++)
        D[i][j][k] = -1;
    }
  }
  scanf("%d%d%d",&N,&M,&P);
  find(0,0,N);
  printf("%lld\n",D[0][0][N]);
}
