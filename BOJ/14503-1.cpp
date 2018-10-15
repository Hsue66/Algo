//#include<iostream>
#include<cstdio>
#define LIMIT 51

using namespace std;

int MAP[LIMIT][LIMIT];
int N,M;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void clean(int x, int y, int d);

void search(int x, int y, int d){
  int i = 0;
  for(; i<4; i++){
    d = (d+3)%4;
    int tx = dir[d][0]+x;
    int ty = dir[d][1]+y;
    if(MAP[tx][ty] == 0){
      clean(tx,ty,d);
      break;
    }
  }

  if(i == 4){
    int tx = dir[(d+2)%4][0]+x;
    int ty = dir[(d+2)%4][1]+y;
    if(MAP[tx][ty] != 1)
      search(tx,ty,d);
  }
}

void clean(int x, int y, int d){
  MAP[x][y] = 2;
  search(x,y,d);
}

int main(){
  scanf("%d%d",&N,&M );
  int r,c,d;
  scanf("%d%d%d",&r,&c,&d);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      scanf("%d",&MAP[i][j]);
  }

  clean(r,c,d);

  int cnt = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      if(MAP[i][j] == 2)
        cnt++;
  }
  printf("%d\n",cnt);
}
