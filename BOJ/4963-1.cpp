#include<cstdio>
//#include<iostream>
#include<queue>
#define LIMIT 51

using namespace std;

int w,h;
int MAP[LIMIT][LIMIT];
int pos[8][2] = {{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{0,1},{1,0},{1,1}};

void bfs(int x,int y){
  queue<pair<int, int> > Q;
  Q.push(make_pair(x,y));
  MAP[x][y] = 0;
  while(!Q.empty()){
    for(int i=0; i<8; i++){
      int tx = Q.front().first + pos[i][0];
      int ty = Q.front().second + pos[i][1];
      if(0 <= tx && tx < h && 0 <= ty && ty < w && MAP[tx][ty] == 1){
        MAP[tx][ty] = 0;
        Q.push(make_pair(tx,ty));
      }
    }
    Q.pop();
  }
}

int main(){
  while(1){
    scanf("%d%d",&w,&h);
    if(w == 0 && h == 0)
      break;

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++)
        scanf("%d",&MAP[i][j]);
    }

    int cnt = 0;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if(MAP[i][j]){
            bfs(i,j);
            cnt++;
        }
      }
    }
    printf("%d\n",cnt);
  }
}
