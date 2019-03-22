#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;

int N,L,R;
int MAP[50][50];
int Union[50][50]={0};
int Dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int Nacc,Ncnt, flag;
queue<pair<int, int> > Queue;
vector<int> Acc;

void makeUnion(){
  while(!Queue.empty()){
    pair<int,int> Now = Queue.front();
    Queue.pop();
    int nx = Now.first;
    int ny = Now.second;
    ++Ncnt;
    Nacc += MAP[nx][ny];
    for(int t=0; t<4; t++){
      int tx = nx+Dir[t][0];
      int ty = ny+Dir[t][1];
      if(0<= tx && tx<N && 0<= ty && ty<N && Union[tx][ty]==0){
        int temp = abs(MAP[nx][ny]-MAP[tx][ty]);
        if(L<=temp && temp <=R){
          flag = 1;
          Union[tx][ty] = Union[nx][ny];
          Queue.push(make_pair(tx,ty));
        }
      }
    }
  }
  Acc.push_back(Nacc/Ncnt);
}



int main(){
  scanf("%d%d%d",&N,&L,&R);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      scanf("%d",&MAP[i][j] );
  }

  int moveP = 0;

  while(1){
    flag = 0;
    // map만들기
    int n=0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(Union[i][j]==0){
          Nacc = 0;
          Ncnt = 0;
          Queue.push(make_pair(i,j));
          Union[i][j] = ++n;
          makeUnion();
        }
      }
    }

    if(flag == 0)
     break;
    moveP++;

    // 인구수정
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++)
        MAP[i][j] = Acc[Union[i][j]-1];
    }

    for(int i=0; i<N; i++)
      fill_n(Union[i],N,0);
    Acc.clear();
  }
  printf("%d\n",moveP );
}
