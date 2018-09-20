#include<cstdio>
//#include<iostream>
#include<queue>
#include<algorithm>
#define LIMIT 26

using namespace std;

int MAP[LIMIT][LIMIT];
int LIST[LIMIT];
int pos[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int N;

void dfs(int x, int y, int cnt){
  int perC = 1;
  queue<pair<int, int> > Q;
  Q.push(make_pair(x,y));
  MAP[x][y] = cnt;
  while(!Q.empty()){
    for(int i =0; i<4; i++){
      int tx = pos[i][0]+ Q.front().first;
      int ty = pos[i][1]+ Q.front().second;
      if(0 <= tx && tx < N && 0 <= ty && ty < N && MAP[tx][ty] == 1){
        MAP[tx][ty] = cnt;
        perC++;
        Q.push(make_pair(tx,ty));
      }
    }
    Q.pop();
  }
  LIST[cnt-2] = perC;
}

int main(){
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      scanf("%1d",&MAP[i][j]);
  }

  int cnt = 2;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(MAP[i][j] == 1){
        dfs(i,j,cnt++);
      }
    }
  }
  sort(LIST,LIST+cnt-2);
  printf("%d\n",cnt-2 );
  for(int i=0; i<cnt-2; i++)
    printf("%d\n",LIST[i]);
}
