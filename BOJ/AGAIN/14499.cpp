#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;

int N,M;
int MAP[20][20];
int DICE[6] = {0};
int Rol[2][4] = {{0,1,3,4},{0,2,3,5}};
int Dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

void rollDice(int dir){
  int d = dir/2;
  deque<int> Temp;
  for(int i=0; i<4; i++)
    Temp.push_back(DICE[Rol[d][i]]);

  if(dir%2 == 0){
    Temp.push_front(Temp.back());
    Temp.pop_back();
  }else{
    Temp.push_back(Temp.front());
    Temp.pop_front();
  }

  for(int i=0; i<4; i++)
    DICE[Rol[d][i]] = Temp[i];
}

int main(){
  int x,y,K;
  scanf("%d%d%d%d%d",&N,&M,&x,&y,&K );
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      scanf("%d",&MAP[i][j] );
  }

  while(K--){
    int d;
    scanf("%d",&d );
    d -= 1;

    int tx = x+Dir[d][0];
    int ty = y+Dir[d][1];
    if(0 <= tx && tx < N && 0<=ty && ty < M){
      x = tx;
      y = ty;
      rollDice(d);
      if(MAP[x][y] == 0)
        MAP[x][y] = DICE[3];
      else{
        DICE[3] = MAP[x][y];
        MAP[x][y] = 0;
      }

      printf("%d\n",DICE[0] );
    }
  }
}
