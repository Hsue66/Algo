#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

vector<vector<pair<int,int> > > Pre;
vector<vector<pair<int,int> > > Active;
int MAP[1000][1000];
int N,M,K;
int Dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};


void decreasePre(){
  vector<pair<int,int> > temp;
  Pre[0].swap(temp);
  for(int i=0; i<11; i++)
    Pre[i].swap(Pre[i+1]);
}

void decreaseActive(){
  vector<pair<int,int> > temp;
  Active[0].swap(temp);
  for(int i=0; i<11; i++)
    Active[i].swap(Active[i+1]);
}

void breedCell(){
  int size = Pre[0].size();
  priority_queue<pair<int,pair<int,int> > > Breed;
  for(int i=0; i<size; i++)
    Breed.push(make_pair(MAP[Pre[0][i].first][Pre[0][i].second],Pre[0][i]));

  while(!Breed.empty()){
    int v = Breed.top().first;
    int x = Breed.top().second.first;
    int y = Breed.top().second.second;
    Active[v].push_back(make_pair(x,y));
    for(int d=0; d<4; d++){
      int tx = x+Dir[d][0];
      int ty = y+Dir[d][1];
      if(MAP[tx][ty] == -1){
        MAP[tx][ty] = v;
        Pre[v+1].push_back(make_pair(tx,ty));
      }
    }
    Breed.pop();
  }
}

int countAlive(){
  int sum = 0;
  for(int i=0; i<11; i++)
    sum += Pre[i].size();
  for(int i=1; i<12; i++)
    sum += Active[i].size();
  return sum;
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    for(int i=0; i<1000; i++)
      fill_n(MAP[i],1000,-1);
    scanf("%d%d%d",&N,&M,&K );
    int x,y;
    x = y = 450;
    vector<vector<pair<int,int> > > pre(12);
    vector<vector<pair<int,int> > > active(12);
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        scanf("%d",&MAP[i+x][j+y] );
        if(MAP[i+x][j+y] == 0)
          MAP[i+x][j+y] = -1;
        else
          pre[MAP[i+x][j+y]].push_back(make_pair(i+x,j+y));
      }
    }
    Pre.swap(pre);
    Active.swap(active);

    while(K--){
      breedCell();
      decreasePre();
      decreaseActive();
    }

    printf("#%d %d\n",t+1,countAlive());
  }
}
