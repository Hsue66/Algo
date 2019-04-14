#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int N,L,R;
int Dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int MAP[50][50], Union[50][50];
queue<pair<int,int> > q;
vector<int> People;


void makeUnion(){
  int sum, cnt;
  sum = cnt = 0;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    sum += MAP[x][y];
    cnt++;
    for(int d=0; d<4; d++){
      int tx = x+Dir[d][0];
      int ty = y+Dir[d][1];
      if(0<=tx && tx<N && 0<=ty && ty<N && Union[tx][ty] == -1){
        int diff = abs(MAP[x][y] - MAP[tx][ty]);
        if(L<= diff && diff <= R){
          q.push(make_pair(tx,ty));
          Union[tx][ty] = Union[x][y];
        }
      }
    }
  }
  People.push_back(sum/cnt);
}

void move(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      MAP[i][j] = People[Union[i][j]];
  }
}

int main(){
  scanf("%d%d%d",&N,&L,&R );
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      scanf("%d",&MAP[i][j] );
  }

  int loop = 0;
  while(1){
    for(int i=0; i<N; i++)
      fill_n(Union[i],N,-1);

    int cnt = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(Union[i][j] == -1){
          q.push(make_pair(i,j));
          Union[i][j] = cnt++;
          makeUnion();
        }
      }
    }
    if(cnt == N*N)
      break;
    move();
    People.clear();
    loop++;
  }
  printf("%d\n",loop );
}
