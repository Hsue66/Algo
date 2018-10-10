//#include<iostream>
#include<cstdio>
#include<cmath>
#define LIMIT 101
#define G_LIMIT 1025

using namespace std;

int MAP[LIMIT][LIMIT]={0};
int Move[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
int Gen;
int Cnt = 0;

void growCurve(int dir[G_LIMIT], int x, int y, int g){
  int sidx = pow(2,g-1)-1;
  int fidx = sidx;

  for(int i=sidx; i >= 0; i--)
    dir[++fidx] = (dir[i] +1)%4;

  for(int i=sidx+1; i<=fidx; i++){
    x = x+Move[dir[i]][0];
    y = y+Move[dir[i]][1];
    MAP[y][x] = 1;
  }
  if(g<Gen)
    growCurve(dir,x,y,g+1);
}

void findSquare(){
  for(int i=0; i<LIMIT-1; i++){
    for(int j=0; j<LIMIT-1; j++){
      if(MAP[i][j]==1 &&MAP[i+1][j]==1 &&MAP[i][j+1]==1 &&MAP[i+1][j+1]==1)
        Cnt++;
    }
  }
}

int main(){
  int N;
  scanf("%d",&N );
  while(N--){
    int x,y;
    int dir[G_LIMIT];
    scanf("%d%d%d%d",&x,&y,&dir[0],&Gen);
    MAP[y][x] = 1;
    x = x+Move[dir[0]][0];
    y = y+Move[dir[0]][1];
    MAP[y][x] = 1;
    if(Gen > 0)
      growCurve(dir, x,y, 1);
  }
  findSquare();
  printf("%d\n",Cnt );
}
