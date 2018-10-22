#include<iostream>
#include<cstdio>
#define LIMIT 11
using namespace std;

int N,M;
char MAP[LIMIT][LIMIT];
int visited[LIMIT][LIMIT];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int Min = 987654321;

int check(pair<int,int> R, pair<int,int> B, int d){
  int res = 0;
  if(d == 0){
    if(R.first < B.first)
      res = 1;
  }else if(d == 1){
    if(R.second > B.second)
      res = 1;
  }else if(d == 2){
    if(R.first > B.first)
      res = 1;
  }else{
    if(R.second < B.second)
      res = 1;
  }
  return res;
}

pair<int,int> move(pair<int,int> xy, int d){
  int tx = xy.first;
  int ty = xy.second;
  while(0<=tx && tx<N && 0<=ty && ty<M){
    tx = tx + dir[d][0];
    ty = ty + dir[d][1];
    if(MAP[tx][ty] == '#' || MAP[tx][ty] == 'R' || MAP[tx][ty] == 'B'){
      tx = tx + dir[(d+2)%4][0];
      ty = ty + dir[(d+2)%4][1];
      return make_pair(tx,ty);
    }else if(MAP[tx][ty] == 'O')
      return make_pair(tx,ty);
  }
  return make_pair(tx,ty);
}

void map(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      cout<<MAP[i][j]<<" ";
      cout<<endl;
    }
}

void dfs(pair<int,int> R, pair<int,int> B, int cnt){
  //char a;
  //cin>>a;
  visited[R.first][R.second] = 1;
  if(MAP[R.first][R.second] != 'O')
    MAP[R.first][R.second] = '.';
  if(MAP[B.first][B.second] != 'O')
    MAP[B.first][B.second] = '.';

  for(int d=0; d<4; d++){
    int startR = check(R,B,d);
    pair<int,int> tR,tB;
    //cout<<R.first<<","<<R.second<<endl;
    //cout<<B.first<<","<<B.second<<endl;
    if(startR == 1){
      tR = move(R,d);
      if(MAP[tR.first][tR.second] != 'O')
        MAP[tR.first][tR.second] = 'R';
      tB = move(B,d);
      if(MAP[tB.first][tB.second] != 'O')
        MAP[tB.first][tB.second] = 'B';
    }else{
      tB = move(B,d);
      if(MAP[tB.first][tB.second] != 'O')
        MAP[tB.first][tB.second] = 'B';
      tR = move(R,d);
      if(MAP[tR.first][tR.second] != 'O')
        MAP[tR.first][tR.second] = 'R';
    }
    if(MAP[tR.first][tR.second] == 'O' && MAP[tB.first][tB.second] != 'O')
      Min = min(Min, cnt+1);

    //cout<<endl;map();
    if(visited[tR.first][tR.second] == 0 && MAP[tB.first][tB.second] != 'O' && MAP[tR.first][tR.second] != 'O')
      dfs(tR,tB,cnt+1);

    if(MAP[tR.first][tR.second] != 'O')
      MAP[tR.first][tR.second] = '.';
    if(MAP[tB.first][tB.second] != 'O')
      MAP[tB.first][tB.second] = '.';
  }
  visited[R.first][R.second] = 0;
}

int main(){
  pair<int,int> R;
  pair<int,int> B;
  scanf("%d%d%*c",&N,&M);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      char t;
      if(M-1 != j)
      scanf("%c",&MAP[i][j]);
      else
        scanf("%c%*c",&MAP[i][j]);
      if(MAP[i][j] == 'R')
        R = make_pair(i,j);
      if(MAP[i][j] == 'B')
        B = make_pair(i,j);
    }
  }
  dfs(R,B,0);
  if(Min == 987654321)
    Min = -1;
  printf("%d\n",Min);
}
