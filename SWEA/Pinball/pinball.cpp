#include<iostream>
#include<cstdio>

using namespace std;

int N,Max,Cnt,StartX,StartY;
int MAP[100][100];
int Hole[5][2],pHole[5][2];
int Dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int Block[5][4] = {{2,0,3,1},{3,2,0,1},{1,3,0,2},{2,3,1,0},{2,3,0,1}};

void move(int x, int y, int d){
  int flag = 0;
  while(1){
    if(MAP[x][y] == -1)
      break;
    if(MAP[x][y] != 0){
      if(MAP[x][y] <= 5){   // 블록
        d = Block[MAP[x][y]-1][d];
        Cnt++;
      }else{                // 웜홀
        int idx = MAP[x][y] - 6;
        if(Hole[idx][0] == x && Hole[idx][1] == y){
          x = pHole[idx][0];
          y = pHole[idx][1];
        }else{
          x = Hole[idx][0];
          y = Hole[idx][1];
        }
      }
    }
    do{
      // cout<<x<<","<<y<<" "<<d<<endl;
      x += Dir[d][0];
      y += Dir[d][1];
      if(!(0 <= x && x < N && 0 <= y && y < N)){  // 벽
        x -= Dir[d][0];
        y -= Dir[d][1];
        d = (d+2)%4;
        Cnt++;
      }
      if(x == StartX && y == StartY){
        flag = 1;
        break;
      }
    }while(MAP[x][y] == 0);

    if(flag)
      break;
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d",&N );
    for(int i=0; i<5; i++){
      fill_n(Hole[i],2,-1);
      fill_n(pHole[i],2,-1);
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        scanf("%d",&MAP[i][j] );
        if(MAP[i][j] > 5){
          int idx = MAP[i][j];
          if(Hole[idx-6][0] == -1){
            Hole[idx-6][0] = i;
            Hole[idx-6][1] = j;
          }else{
            pHole[idx-6][0] = i;
            pHole[idx-6][1] = j;
          }
        }
      }
    }

    Max = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(MAP[i][j] == 0){
          for(int d=0; d<4; d++){
            Cnt = 0;
            StartX = i; StartY = j;
            move(i,j,d);
            Max = max(Max,Cnt);
          }
        }
      }
    }
    printf("#%d %d\n",t+1,Max );
  }
}
