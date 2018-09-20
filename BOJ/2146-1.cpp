#include<cstdio>
#include<iostream>
#include<queue>
#define LIMIT 101

using namespace std;

int N;
int MAP[LIMIT][LIMIT];
int LAND[LIMIT][LIMIT];
int pos[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
queue<pair<int, int> > Q;

void spread(){
  while(!Q.empty()){
    for(int i =0; i<4; i++){
      int tx = pos[i][0]+ Q.front().first;
      int ty = pos[i][1]+ Q.front().second;
      if(0 <= tx && tx < N && 0 <= ty && ty < N && MAP[tx][ty] == 0){
        MAP[tx][ty] = MAP[Q.front().first][Q.front().second]+1;
        LAND[tx][ty] = LAND[Q.front().first][Q.front().second];
        Q.push(make_pair(tx,ty));
      }
    }
    Q.pop();
  }
}

void findLand(int x, int y, int cnt){
  queue<pair<int, int> > q;
  q.push(make_pair(x,y));
  LAND[x][y] =cnt;
  while(!q.empty()){
    for(int i =0; i<4; i++){
      int tx = pos[i][0]+ q.front().first;
      int ty = pos[i][1]+ q.front().second;
      if(0 <= tx && tx < N && 0 <= ty && ty < N && LAND[tx][ty] == 1){
        LAND[tx][ty] = cnt;
        q.push(make_pair(tx,ty));
      }
    }
    q.pop();
  }
}


int main(){
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      scanf("%d",&MAP[i][j]);
      LAND[i][j] = MAP[i][j];
      if(MAP[i][j] == 1)
        Q.push(make_pair(i,j));
    }
  }

  int cnt = 2;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(LAND[i][j]==1){
        findLand(i,j,cnt++);
      }
    }
  }
  spread();

  int Min = LIMIT*LIMIT;
  for(int i=0; i<N-1; i++){
    for(int j=0; j<N-1; j++){
      if(LAND[i][j] != LAND[i][j+1])
        Min = min(Min, MAP[i][j]+MAP[i][j+1]);
      if(LAND[i][j] != LAND[i+1][j])
        Min = min(Min, MAP[i][j]+MAP[i+1][j]);
    }
  }
  if(Min == LIMIT*LIMIT)
    printf("0\n");
  else
    printf("%d\n",Min-2);
}
