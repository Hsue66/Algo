//#include<iostream>
#include<cstdio>
#include<deque>
#define LIMIT 101

using namespace std;

int N,K,L;
int MAP[LIMIT][LIMIT];
deque<pair<int,char> > Turn;
deque<pair<int,int> > Snake;
int Dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

void moveSnake(int x, int y, int d, int t){
  if(Turn.front().first == t){
    if(Turn.front().second == 'L')
      d = (d+1)%4;
    else
      d = (d+3)%4;
    Turn.pop_front();
  }
  x = x+Dir[d][0];
  y = y+Dir[d][1];

  t++;
  int flag = 1;
  if(0 <= x && x < N && 0 <= y && y < N){
    Snake.push_front(make_pair(x,y));
    if(MAP[x][y] == 0){
      MAP[Snake.back().first][Snake.back().second] = 0;
      Snake.pop_back();
    }
    else if(MAP[x][y] == 2)
      flag = 0;
    MAP[x][y] = 2;
  }
  else
    flag = 0;


  if(flag)
    moveSnake(x,y,d,t);
  else
    printf("%d\n",t);
}

int main(){
  scanf("%d",&N);
  scanf("%d",&K);
  for(int i=0; i<K; i++){
    int tx,ty;
    scanf("%d%d",&tx,&ty );
    MAP[tx-1][ty-1] = 1;
  }
  scanf("%d",&L);
  for(int i=0; i<L; i++){
    int t;
    char c;
    scanf("%d %c",&t,&c );
    Turn.push_back(make_pair(t,c));
  }

  Snake.push_front(make_pair(0,0));
  MAP[0][0] = 2;
  moveSnake(0,0,0,0);
}
