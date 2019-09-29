#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int N,M,Cnt,Max;
int MAP[20][20];

void col(int x, int ty, int i, int k){
  for(int j=1; j<k-i; j++){
    int tx = x-j;
    if( 0 <= tx && tx < N && MAP[tx][ty] == 1)
      Cnt++;
    tx = x+j;
    if( 0 <= tx && tx < N && MAP[tx][ty] == 1)
      Cnt++;
  }
}

void service(int x, int y, int k){
  for(int i=0; i<k; i++){
    int ty = y-i;
    if(0 <= ty && ty < N){
      if(MAP[x][ty] == 1)
        Cnt++;
      col(x,ty,i,k);
    }
    if(i == 0)
      continue;
    ty = y+i;
    if(0 <= ty && ty < N){
      if(MAP[x][ty] == 1)
        Cnt++;
      col(x,ty,i,k);
    }
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d",&N,&M );
    int all=0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        scanf("%d",&MAP[i][j] );
        if(MAP[i][j] == 1)
          all++;
      }
    }

    int K = N*2;
    Max = 1;
    for(; K > 1; K--){
      if(pow(K,2)+pow(K-1,2) <= M*all)
        break;
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        for(int k=2; k<=K; k++){
          Cnt = 0;
          int install = pow(k,2)+pow(k-1,2);
          service(i,j,k);
          if(Cnt*M - install >= 0)
            Max = max(Max,Cnt);
        }
      }
    }

    printf("#%d %d\n",t+1,Max );
  }
}
