#include<cstdio>
//#include<iostream>
#include<queue>
#define LIMIT 100

using namespace std;

int N,M;
int MAP[LIMIT][LIMIT];
int pos[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

void bfs(int x,int y){
  queue<pair<int,int> > Q;
  Q.push(make_pair(x,y));
  MAP[x][y] = 2;
  while(!Q.empty()){
    for(int i =0; i<4; i++){
      int tx = pos[i][0]+ Q.front().first;
      int ty = pos[i][1]+ Q.front().second;
      if(0 <= tx && tx < N && 0 <= ty && ty < M && MAP[tx][ty] == 1){
        MAP[tx][ty] = MAP[Q.front().first][Q.front().second]+1;
        Q.push(make_pair(tx,ty));
      }
    }
    Q.pop();
  }
}

int main(){
  scanf("%d%d",&N,&M);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      scanf("%1d",&MAP[i][j]);
  }
  bfs(0,0);
  printf("%d\n",MAP[N-1][M-1]-1);
}
