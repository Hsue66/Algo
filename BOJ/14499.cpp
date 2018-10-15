//#include<iostream>
#include<cstdio>

using namespace std;

int Dir[4][2] ={{0,1},{0,-1},{-1,0},{1,0}};
int line[2][4] = {{0,1,3,4},{0,2,3,5}};
int N,M,x,y,K;
int MAP[21][21];

void moveDice(int dir, int dice[6]){
  int loop[4];
  //line[cnt+1/2][4];
  for(int i=0; i<4; i++){
    loop[i] = dice[line[(dir-1)/2][i]];
    dice[line[(dir-1)/2][i]] = 0;
  }

  int sIdx = 3;
  if(dir/2 == 1)
    sIdx = 1;

  for(int i=0; i<4; i++)
    dice[line[(dir-1)/2][i]] = loop[(sIdx+i)%4];
}

int main(){
  scanf("%d%d%d%d%d",&N,&M,&x,&y,&K);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      scanf("%d",&MAP[i][j] );
  }

  int dice[6] = {0};
  for(int i=0; i<K; i++){
    int dir;
    scanf("%d",&dir);
    int tx = Dir[dir-1][0]+x;
    int ty = Dir[dir-1][1]+y;
    if(0 <= tx && tx < N && 0 <= ty && ty < M){
      x = tx;
      y = ty;
      moveDice(dir,dice);
      if(MAP[x][y] == 0)
        MAP[x][y] = dice[3];
      else{
        dice[3] = MAP[x][y];
        MAP[x][y] = 0;
      }
      printf("%d\n",dice[0]);
    }
  }
}
