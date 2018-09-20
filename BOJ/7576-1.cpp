#include<cstdio>
#include<iostream>
#include<queue>
#define LIMIT 1001

using namespace std;

int N,M;
int MAP[LIMIT][LIMIT];
int pos[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
queue<pair<int, int> > Q;

void bfs(){
  while(!Q.empty()){
    for(int i =0; i<4; i++){
      int tx = pos[i][0]+ Q.front().first;
      int ty = pos[i][1]+ Q.front().second;
      if(0 <= tx && tx < N && 0 <= ty && ty < M && MAP[tx][ty] == 0){
        MAP[tx][ty] = MAP[Q.front().first][Q.front().second]+1;
        Q.push(make_pair(tx,ty));
      }
    }
    Q.pop();
  }
}

int main(){
  scanf("%d%d",&M,&N);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d",&MAP[i][j]);
      if(MAP[i][j] == 1)
        Q.push(make_pair(i,j));
    }
  }

  bfs();
  int flag = 0;
  int MAX = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      //cout<<MAP[i][j]<<" ";
      if(MAP[i][j] == 0)
        flag = 1;
      MAX = max(MAP[i][j],MAX);
    }
    //cout<<endl;
  }
  if(flag)
    printf("-1\n");
  else
    printf("%d\n",MAX-1);
}
