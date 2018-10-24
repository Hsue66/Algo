#include<iostream>
#include<cstdio>
#define LIMIT 32

using namespace std;

int N;
long long D[LIMIT][LIMIT];

long long find(int x, int y){
  if(D[x][y] != -1)
    return D[x][y];
  else{
    long long t1 = 0;
    long long t2 =0;
    if(x-1 >= 0){
      if(D[x-1][y+1] != -1)
        t1 = D[x-1][y+1];
      else
        t1 = find(x-1,y+1);
    }

    if(y-1 >= 0){
      if(D[x][y-1] != -1)
        t2 = D[x][y-1];
      else
        t2 = find(x,y-1);
    }
    return t1+t2;
  }
}

void find(){
  for(int i=1; i<LIMIT-1; i++){
    for(int j=0; j<LIMIT-1-i; j++){
      D[i][j] = D[i-1][j+1];
      if(j-1 >= 0)
        D[i][j] += D[i][j-1];
    }
  }
}

int main(){
  for(int i=1; i<LIMIT; i++)
    fill_n(D[i],LIMIT,-1);
  fill_n(D[0],LIMIT,1);
  D[0][0] = 0;

  find();
  while(1){
    scanf("%d",&N);
    if(N==0)
      break;
    printf("%lld\n",D[N][0]);
  }
}
