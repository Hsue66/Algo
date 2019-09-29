#include<iostream>
#include<cstdio>

using namespace std;

int N, Max;
int MAP[20][20];
int Desert[100]={0};
int Dir[4][2] = {{1,-1},{1,1},{-1,1},{-1,-1}};

void path(int Nx,int Ny, int dir, int d[100], int w, int h){
  int t[100];
  copy(d,d+100,t);

  int Tx = Nx;
  int Ty = Ny;
  if(dir > 1){
    int l = w;
    if(dir == 3) l = h-1;

    int flag = 0;
    while(l--){
      Tx += Dir[dir][0];
      Ty += Dir[dir][1];
      if(0<=Tx && Tx<N && 0<=Ty && Ty<N && d[MAP[Tx][Ty]-1] != 1 && t[MAP[Tx][Ty]-1] != 1)
        t[MAP[Tx][Ty]-1] = 1;
      else
        flag = 1;
    }

    if(flag == 0){
      if(dir == 2)
        path(Tx,Ty,dir+1,t,w,h);
      else{
        if(Max < (w+h)*2)
          Max = (w+h)*2;
      }
    }
  }else{
    Tx += Dir[dir][0];
    Ty +=Dir[dir][1];
    while(0<=Tx && Tx<N && 0<=Ty && Ty<N && d[MAP[Tx][Ty]-1] != 1 && t[MAP[Tx][Ty]-1] != 1){
      if(dir == 0) w++;
      else  h++;
      t[MAP[Tx][Ty]-1] = 1;
      //cout<<MAP[Tx][Ty]<<":"<<Tx<<","<<Ty<<endl;
      path(Tx,Ty,dir+1,t,w,h);
      Tx += Dir[dir][0];
      Ty += Dir[dir][1];
    }
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=1; t<=testcase; t++){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++)
        scanf("%d",&MAP[i][j]);
    }
    Max = -1;
    for(int i=0; i<N-2; i++){
      for(int j=1; j<N-1; j++){
        Desert[MAP[i][j]-1] = 1;
        path(i,j,0,Desert,0,0);
        fill_n(Desert,100,0);
      }
    }
    printf("#%d %d\n",t,Max );
  }
}
