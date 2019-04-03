#include<iostream>
#include<cstdio>

using namespace std;

int N,M;
int MAX = 0;
int MAP[500][500];
int Case[2][57] = {
                    {0,0,0, 1,2,3, 0,1,1, 0,0,1, 0,0,1, 1,2,2,  1,2,2, 1,1,1, 1,1,1,   0,1,2, 0,1,2, 0,1,1, 1,1,2,   1,1,2, 0,1,1,    0,0,1, 1,2,1, 0,0,-1, 1,2,1},
                    {1,2,3, 0,0,0, 1,1,0, 1,2,2, 1,2,0, 0,0,-1, 0,0,1, 0,1,2, 0,-1,-2, 1,0,0, 1,1,1, 1,1,2, 0,-1,-1, 0,1,1, -1,-1,-2, 1,2,1, 0,0,1, 1,2,1,  0,0,-1}};

int main(){
  scanf("%d%d",&N,&M );
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      scanf("%d",&MAP[i][j] );
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      for(int c=0; c<19; c++){
        int sum = MAP[i][j];
        int flag = 1;
        for(int t=0; t<3 && flag == 1; t++){
          int tx = i+Case[0][c*3+t];
          int ty = j+Case[1][c*3+t];
          if(0<=tx && tx< N && 0<=ty && ty< M)
            sum += MAP[tx][ty];
          else
            flag = 0;
        }
        if(flag)
          MAX = max(MAX,sum);
      }
    }
  }

  printf("%d\n",MAX );
}
