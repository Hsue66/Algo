#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

int MAP[101][101] = {0};
int DRAGON[20][4];
int N;
int Dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int Cnt =0;

void moveDragon(int idx){
  int d = DRAGON[idx][2];
  int Nx = DRAGON[idx][0]+Dir[d][0];
  int Ny = DRAGON[idx][1]+Dir[d][1];
  if( 0 <= Nx && Nx <= 100 && 0 <= Ny && Ny <= 100){
    MAP[Nx][Ny] = 1;
    stack<int> S;
    S.push(d);
    for(int i=1; i<=DRAGON[idx][3]; i++){
      int flag = 0;
      stack<int> bs;
      queue<int> temp;
      while(!S.empty()){
        bs.push(S.top());
        int d = (S.top()+1)%4;
        S.pop();
        Nx += Dir[d][0];
        Ny += Dir[d][1];
        if( 0 <= Nx && Nx <= 100 && 0 <= Ny && Ny <= 100){
          MAP[Nx][Ny] = 1;
          temp.push(d);
        }else{
          flag = 1;
          break;
        }
      }
      if(flag)
        break;
      while(!bs.empty()){
        S.push(bs.top());
        bs.pop();
      }
      while(!temp.empty()){
        S.push(temp.front());
        temp.pop();
      }
    }
  }
}

int main(){
  scanf("%d",&N );
  for(int i=0; i<N; i++){
    scanf("%d%d%d%d",&DRAGON[i][1],&DRAGON[i][0],&DRAGON[i][2],&DRAGON[i][3] );
    MAP[DRAGON[i][0]][DRAGON[i][1]] = 1;
  }
  for(int i=0; i<N; i++)
    moveDragon(i);

  for(int i=0; i<100; i++){
    for(int j=0; j<100; j++)
      if(MAP[i][j] == 1 && MAP[i][j+1] == 1 && MAP[i+1][j] == 1 && MAP[i+1][j+1] == 1)
        Cnt++;
  }
  printf("%d\n",Cnt );
}
