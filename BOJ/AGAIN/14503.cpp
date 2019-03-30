#include<iostream>
#include<cstdio>

using namespace std;

int MAP[50][50];
int N,M;
int Cnt;
int Dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void move(int Nx, int Ny, int dir){
  int flag = 0;
  int d = dir;
  for(int i=0; i<4; i++){
    d = (d+3)%4;
    int tx = Nx+Dir[d][0];
    int ty = Ny+Dir[d][1];
    if(MAP[tx][ty] == 0){
      Nx = tx;
      Ny = ty;
      dir = d;
      flag = 1;
      break;
    }
  }
  if(flag){
    MAP[Nx][Ny] = -1;
    Cnt++;
    move(Nx,Ny,dir);
  }else{
    int d = (dir+2)%4;
    int tx = Nx+Dir[d][0];
    int ty = Ny+Dir[d][1];
    if(MAP[tx][ty] != 1)
      move(tx,ty,dir);
  }
}

int main(){
  scanf("%d%d",&N,&M );
  int r,c,d;
  scanf("%d%d%d",&r,&c,&d );
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      scanf("%d",&MAP[i][j] );
  }

  MAP[r][c] = -1;
  Cnt = 1;
  move(r,c,d);

  printf("%d\n",Cnt );
}
