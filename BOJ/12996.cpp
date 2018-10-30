//#include<iostream>
#include<cstdio>
#define LIMIT 1000000007

using namespace std;

int S;
int D[51][51][51][51];
int cases[7][3] = {{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,1,1}};

void findAll(int n, int x, int y, int z){
  for(int i=0; i<7; i++){
    int tx = x-cases[i][0];
    int ty = y-cases[i][1];
    int tz = z-cases[i][2];

    if(tx < 0 || ty < 0 || tz < 0)
      continue;

    if(n+1 == S && !(tx == 0 && ty == 0 && tz == 0))
        D[n+1][tx][ty][tz] = 0;

    if(D[n+1][tx][ty][tz] == -1){
      D[n+1][tx][ty][tz] = 0;
      findAll(n+1,tx,ty,tz);
    }

    D[n][x][y][z] = (D[n+1][tx][ty][tz] + D[n][x][y][z]) % LIMIT;
  }
}

int main(){
  for(int i=0; i<51; i++){
    for(int j=0; j<51; j++){
      for(int k=0; k<51; k++){
        for(int l=0; l<51; l++)
          D[i][j][k][l] = -1;
      }
    }
  }

  scanf("%d",&S);
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  D[S][0][0][0] = 1;
  D[0][x][y][z] = 0;
  findAll(0,x,y,z);
  printf("%d\n",D[0][x][y][z]);
}
