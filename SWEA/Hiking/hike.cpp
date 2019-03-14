#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int MAP[9][9];
int PATH[9][9] = {0};
int N,K;
vector<pair<int,int> > MAXs;
int Dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int flag = 0;
int LenP;

void makeRoad(pair<int,int> Now, int cnt){
  int nX = Now.first;
  int nY = Now.second;
  //4방향탐색
  for(int i=0; i<4; i++){
    int tX = Now.first+Dir[i][0];
    int tY = Now.second+Dir[i][1];

    if(0<=tX && tX<N && 0<=tY && tY<N && PATH[tX][tY]==0){
      //cout<<tX<<" "<<tY<<endl;
      if(MAP[tX][tY] < PATH[nX][nY]){
        PATH[tX][tY] = MAP[tX][tY];
        makeRoad(make_pair(tX,tY),cnt+1);
        PATH[tX][tY] = 0;
      }
      else{
        if(!flag){
          if(MAP[tX][tY]-K < PATH[nX][nY]){
            flag = 1;
            PATH[tX][tY] = PATH[nX][nY]-1;
            makeRoad(make_pair(tX,tY),cnt+1);
            PATH[tX][tY] = 0;
            flag = 0;
          }else{
            if(LenP < cnt)
              LenP = cnt;
          }
        }else{
          if(LenP < cnt)
            LenP = cnt;
        }
      }
    }
  }
}

int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int t=1; t<=testcase; t++){
      scanf("%d%d",&N,&K);
      LenP = 0;
      int max = 0;
      for(int i =0; i<N; i++){
        for(int j=0; j<N; j++){
          scanf("%d",&MAP[i][j]);
          if(max < MAP[i][j])
            max = MAP[i][j];
        }
      }

      // max위치 찾기
      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          if(MAP[i][j] == max)
            MAXs.push_back(make_pair(i,j));
        }
      }
      // for(int i=0; i<MAXs.size(); i++)
      //   cout<<MAXs[i].first<<" "<<MAXs[i].second<<endl;

      while(!MAXs.empty()){
        pair<int, int> BACK = MAXs.back();
        //Points.push(BACK);
        PATH[BACK.first][BACK.second] = MAP[BACK.first][BACK.second];
        makeRoad(BACK,1);
        MAXs.pop_back();
        PATH[BACK.first][BACK.second] = 0;
      }

      printf("#%d %d\n",t,LenP);
      for(int i =0; i<N; i++)
        fill_n(MAP[i],N,0);
    }
}
