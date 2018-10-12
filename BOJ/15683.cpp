//#include<iostream>
#include<cstdio>
#include<vector>
#define LIMIT 9

using namespace std;
int N,M;
int MAP[LIMIT][LIMIT];
vector<pair<int,pair<int,int> > > CCTV;
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
int COVER[4];

void search(int cx, int cy){
  for(int i=0; i<4; i++){
    int cnt = 0;
    int x = cx;
    int y = cy;
    while(1){
      x = x+dir[i][0];
      y = y+dir[i][1];
      if(x<0 || y<0 || N <= x || M <= y || MAP[x][y] == 6)
        break;
      ++cnt;
    }
    COVER[i] = cnt;
  }
}

void cover(int cx, int cy,int idx){
  int x = cx;
  int y = cy;
  while(1){
    x = x+dir[idx][0];
    y = y+dir[idx][1];
    if(x<0 || y<0 || N <= x || M <= y || MAP[x][y] == 6)
      break;
    MAP[x][y] = -1;
  }
}

int main(){
  scanf("%d%d",&N,&M);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d",&MAP[i][j]);
      if( 0 < MAP[i][j] && MAP[i][j] < 6)
        CCTV.push_back(make_pair(MAP[i][j],make_pair(i,j)));
    }
  }

  for(int i=0; i<CCTV.size(); i++){
    int type = CCTV[i].first;
    int cx = CCTV[i].second.first;
    int cy = CCTV[i].second.second;

    search(cx,cy);

    int Max = 0;
    int idx = 0;
    if(type == 1){
      for(int i=0; i<4; i++){
        if(Max < COVER[i]){
          Max = COVER[i];
          idx = i;
        }
      }
      cover(cx,cy,idx);
    }else if(type == 2){
      if(COVER[0]+COVER[2] > COVER[1]+COVER[3] ){
        cover(cx,cy,0);
        cover(cx,cy,2);
      }else{
        cover(cx,cy,1);
        cover(cx,cy,3);
      }
    }else if(type == 3){
      for(int i=0; i<4; i++){
        if(COVER[i] + COVER[(i+1)%4] > Max){
          Max = COVER[i] + COVER[(i+1)%4];
          idx = i;
        }
      }
      cover(cx,cy,idx);
      cover(cx,cy,(idx+1)%4);
    }else if(type == 4){
      for(int i=0; i<4; i++){
        if(COVER[i] + COVER[(i+1)%4] + COVER[(i+2)%4] > Max){
          Max = COVER[i] + COVER[(i+1)%4] + COVER[(i+2)%4];
          idx = i;
        }
      }
      cover(cx,cy,idx);
      cover(cx,cy,(idx+1)%4);
      cover(cx,cy,(idx+2)%4);
    }
    else{
      cover(cx,cy,0);
      cover(cx,cy,1);
      cover(cx,cy,2);
      cover(cx,cy,3);
    }
  }

  int Cnt = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(MAP[i][j] == 0)
        Cnt++;
    }
  }
  printf("%d\n",Cnt );
}
