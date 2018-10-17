#include<iostream>
#include<cstdio>
#define LIMIT 101

using namespace std;

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int MAP[LIMIT][LIMIT];
int N,L;
int Cnt;
int visited[LIMIT][LIMIT];

void check(int x, int y, int d, int h){
  //cout<<x<<", "<<y<<endl;
  if(x == N || y == N)
    Cnt++;
  else{
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    int tx = x;
    int ty = y;
    int c = 0;
    if(h-MAP[x][y] == -1){
      int td = (d+2)%4;
      for(int i=0; i<L; i++){
        tx = tx + dir[td][0];
        ty = ty + dir[td][1];
        if(0<=tx && tx<N && 0<=ty && ty<N && MAP[tx][ty]==MAP[x+dir[td][0]][y+dir[td][1]] && visited[tx][ty] == 0){
          c++;
          visited[tx][ty] = 1;
        }
      }
      if(c==L)
        check(nx,ny,d,MAP[x][y]);
    }
    else if(h-MAP[x][y] == 1){
      for(int i=0; i<L; i++){
        if(0<=tx && tx<N && 0<=ty && ty<N && MAP[tx][ty]==MAP[x][y] && visited[tx][ty] == 0){
          c++;
          visited[tx][ty] = 1;
        }
        tx = tx + dir[d][0];
        ty = ty + dir[d][1];
      }
      if(c==L)
        check(tx,ty,d,MAP[x][y]);
    }
    else if(MAP[x][y]-h == 0)
      check(nx,ny,d,MAP[x][y]);
  }
}

int main(){
  scanf("%d%d",&N,&L);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      scanf("%d",&MAP[i][j]);
  }

  Cnt = 0;
  for(int i=0; i<N; i++)
    check(i,1,0,MAP[i][0]);

  for(int i=0; i<N; i++)
    fill_n(visited[i],N,0);

  for(int i=0; i<N; i++)
    check(1,i,1,MAP[0][i]);
  printf("%d\n",Cnt);
}
