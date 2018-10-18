//#include<iostream>
#include<cstdio>
#include<stack>
#define LIMIT 101

using namespace std;

int MAP[LIMIT][LIMIT];
int G;
int dir[4][2]= {{0,1},{-1,0},{0,-1},{1,0}};

void move(int x, int y, stack<int> S, int g){
  stack<int> cS;
  cS = S;
  if(g < G){
    while(!S.empty()){
      int d = (S.top()+1)%4;
      S.pop();
      cS.push(d);
      x = x+dir[d][0];
      y = y+dir[d][1];
      MAP[x][y] = 1;
    }
    move(x,y,cS,g+1);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  while(N--){
    int x,y,d;
    scanf("%d%d%d%d",&y,&x,&d,&G);
    MAP[x][y] = 1;
    MAP[x+dir[d][0]][y+dir[d][1]] = 1;
    stack<int> S;
    S.push(d);
    move(x+dir[d][0],y+dir[d][1],S,0);
  }

  int cnt = 0;
  for(int i=0; i<LIMIT-1; i++){
    for(int j=0; j<LIMIT-1; j++){
      if(MAP[i][j] == 1 && MAP[i+1][j] == 1 && MAP[i][j+1] == 1 && MAP[i+1][j+1] == 1)
        cnt++;
    }
  }
  printf("%d\n",cnt);
}
