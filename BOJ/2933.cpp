#include<iostream>
#include<cstdio>
#include<deque>
#include<queue>
#include<algorithm>
#define LIMIT 101

using namespace std;

int R,C,N;
char MAP[LIMIT][LIMIT];
int visited[LIMIT][LIMIT];
int cluster[LIMIT][LIMIT];
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

void move(deque<int> Cluster[LIMIT]){
  int Cnt = LIMIT;
  for(int i=0; i<C; i++){
    for(int j=0; j<Cluster[i].size(); j++){
      int cnt = 0;
      int y = Cluster[i][j];
      for(int j=y+1; j<R; j++){
        if(MAP[j][i] == 'x' && cluster[j][i] != 1){
          cnt = j-y-1;
          break;
        }
      }
      if(cnt == 0)
        cnt = R-1-y;

      Cnt = min(cnt,Cnt);
    }
  }

  for(int i=0; i<C; i++){
    for(int j=0; j<Cluster[i].size(); j++)
      MAP[Cluster[i][j]][i] = '.';
  }

  for(int i=0; i<C; i++){
    for(int j=0; j<Cluster[i].size(); j++)
      MAP[Cluster[i][j]+Cnt][i] = 'x';
  }

  for(int i=0; i<C; i++)
    Cluster[i].clear();
}

void bfs(int x, int y){
  int flag = 1;
  queue<pair<int,int> > Q;
  deque<int> Cluster[C];

  Q.push(make_pair(x,y));
  cluster[x][y] = 1;
  Cluster[y].push_back(x);
  visited[x][y] = 1;
  while(!Q.empty() && flag == 1){
    int x = Q.front().first;
    int y = Q.front().second;
    Q.pop();
    for(int i=0; i<4; i++){
      int tx = x+ dir[i][0];
      int ty = y+ dir[i][1];
      if(0<=tx && tx<R && 0<=ty && ty<C && MAP[tx][ty]=='x' && visited[tx][ty] == 0){
        if(tx == R-1){
          flag = 0;
          break;
        }
        visited[tx][ty] = 1;
        Q.push(make_pair(tx,ty));
        cluster[tx][ty] = 1;
        Cluster[ty].push_back(tx);
      }
    }
  }
  while(!Q.empty())
    Q.pop();

  if(flag == 0){
    for(int i=0; i<C; i++)
      Cluster[i].clear();
  }
  else
    move(Cluster);
}

void check(int x, int y, int d){
  for(int i=0; i<4; i++){
    for(int i=0; i<R; i++){
      fill_n(visited[i],C, 0);
      fill_n(cluster[i],C, 0);
    }
    int tx = x+ dir[i][0];
    int ty = y+ dir[i][1];
    if(0<=tx && tx<R && 0<=ty && ty<C && MAP[tx][ty]=='x' && visited[tx][ty] == 0){
      bfs(tx,ty);
    }
  }
}

void throwBar(int h, int d){
  int add = 1;
  int start = 0;
  if(d==1){
    add = -1;
    start = C-1;
  }

  int x,y;
  for(int i=0; i<C; i++){
    if(MAP[R-h][start+(add*i)] == 'x'){
      MAP[R-h][start+(add*i)] = '.';
      x = R-h;
      y = start+(add*i);
      break;
    }
  }
  check(x,y,d);
}

int main(){
  scanf("%d%d%*c",&R,&C);
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(j!=C-1)
        scanf("%c",&MAP[i][j]);
      else
        scanf("%c%*c",&MAP[i][j]);
    }
  }
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    int h;
    scanf("%d",&h);
    throwBar(h, i%2);
  }
  
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++)
      printf("%c",MAP[i][j]);
    printf("\n");
  }
}
