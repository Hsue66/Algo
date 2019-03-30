#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int N,M;
int MAP[8][8];
int Temp[8][8];
vector<pair<int,int> > Virus;
vector<pair<int,int> > possible;
int Safe, Dsafe, Max;
int Dir[4][2] ={{0,-1},{0,1},{-1,0},{1,0}};

void spread(pair<int,int> start){
  queue<pair<int,int> > vq;
  vq.push(start);
  while(!vq.empty()){
    int nx = vq.front().first;
    int ny = vq.front().second;
    vq.pop();
    for(int i=0; i<4; i++){
      int tx = nx+Dir[i][0];
      int ty = ny+Dir[i][1];
      if(0<= tx && tx < N && 0<= ty && ty < M && Temp[tx][ty] == 0){
        Temp[tx][ty] = 2;
        vq.push(make_pair(tx,ty));
        Dsafe--;
      }
    }
  }
}

void build(int idx, int cnt){
  if(cnt == 3){
    int vlen = Virus.size();
    Dsafe = Safe-3;
    for(int i=0; i<N; i++)
      copy(MAP[i],MAP[i]+M, Temp[i]);
    for(int i=0; i<vlen; i++)
      spread(Virus[i]);
    Max = max(Max,Dsafe);
  }else{
    for(int i=idx; i<Safe; i++){
      int nx = possible[i].first;
      int ny = possible[i].second;
      MAP[nx][ny] = 1;
      build(i+1, cnt+1);
      MAP[nx][ny] = 0;
    }
  }
}

int main(){
  scanf("%d%d",&N,&M );
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d",&MAP[i][j] );
      if(MAP[i][j] == 2)
        Virus.push_back(make_pair(i,j));
      else if(MAP[i][j] == 0)
        possible.push_back(make_pair(i,j));
    }
  }

  Safe = possible.size();
  Max = 0;


  build(0,0);
  printf("%d\n",Max );



  // for(int i=0; i<N; i++){
  //   for(int j=0; j<M; j++)
  //     cout<<Temp[i][j]<<" ";
  //     cout<<endl;
  // }
}
