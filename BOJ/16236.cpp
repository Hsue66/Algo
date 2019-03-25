#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int N;
int MAP[20][20];
pair<int,int> sharkP;
vector<pair<int,int> > eatable;
vector<pair<int,pair<int,int> > > bigfish;
int sharkSize = 2;
int Dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int cnt = 0;
int Time = 0;

void moveShark(){
  queue<pair<int,int> > q;
  q.push(sharkP);
  while(!q.empty()){
    pair<int,int> now = q.front();
    int x = now.first;
    int y = now.second;
    q.pop();
    for(int i=0; i<4; i++){
      int tx = x + Dir[i][0];
      int ty = y + Dir[i][1];
      if(0<=tx && tx < N && 0<=ty && ty < N){
        if(MAP[x][y] + 1 < MAP[tx][ty]){
          MAP[tx][ty] = MAP[x][y] + 1;
          q.push(make_pair(tx,ty));
        }
      }
    }
  }
}

void eatFish(){

  while(1){
    if(eatable.empty())
      break;

    moveShark();

    // 짧은 거리애 먹기
    pair<int,int> eatP = eatable[0];
    vector<pair<int,int> > temp;
    int eatlen = eatable.size();
    int min = MAP[eatable[0].first][eatable[0].second];

    for(int i=1; i<eatlen; i++){
      pair<int,int> now = eatable[i];
      if(min > MAP[now.first][now.second]){
        temp.push_back(eatP);
        min = MAP[now.first][now.second];
        eatP = now;
      }
      else if(min == MAP[now.first][now.second]){
        if(now.first < eatP.first){
          temp.push_back(eatP);
          eatP = now;
        }
        else if(now.first == eatP.first){
          if(now.second < eatP.second){
            temp.push_back(eatP);
            eatP = now;
          }
          else
            temp.push_back(now);
        }
        else
          temp.push_back(now);
      }
      else
        temp.push_back(now);
    }
    eatable = temp;
    if(min == N*N)
      break;

    cnt++;
    Time += min;
    sharkP = eatP;

    // 맵 다시 set
    for(int i=0; i<N; i++)
      fill_n(MAP[i],N,N*N);
    MAP[sharkP.first][sharkP.second] = 0;

    if(cnt == sharkSize){ // 크기증가
      cnt = 0;
      sharkSize++;
    }
    vector<pair<int,pair<int,int> > > bigtemp;
    int biglen = bigfish.size();
    for(int i=0; i<biglen; i++){
      int nsize = bigfish[i].first;
      int tx = bigfish[i].second.first;
      int ty = bigfish[i].second.second;
      if(nsize < sharkSize)
        eatable.push_back(bigfish[i].second);
      else if(nsize > sharkSize){
        MAP[tx][ty] = -1;
        bigtemp.push_back(bigfish[i]);
      }else{
        bigtemp.push_back(bigfish[i]);
      }
    }
    bigfish = bigtemp;
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    fill_n(MAP[i],N,N*N);
    for(int j=0; j<N; j++){
      int temp;
      scanf("%d",&temp );
      if(temp == 9){
        MAP[i][j] = 0;
        sharkP = make_pair(i,j);
      }
      else if(temp < sharkSize && temp != 0)
        eatable.push_back(make_pair(i,j));
      else if(temp > sharkSize){
        MAP[i][j] = -1;
        bigfish.push_back(make_pair(temp,make_pair(i,j)));
      }
      else if(temp == sharkSize)
        bigfish.push_back(make_pair(temp,make_pair(i,j)));
    }
  }

  eatFish();
  printf("%d\n",Time );
}


// cout<<"-----------------------"<<endl;
// cout<<Time<<endl;
// for(int i=0; i<N; i++){
//   for(int j=0; j<N; j++)
//   cout<<MAP[i][j]<<" ";
//   cout<<endl;
// }
// cout<<sharkP.first<<" "<<sharkP.second<<endl;
//
// cout<<"eatable"<<endl;
// for(int i=0; i<eatable.size(); i++)
//   cout<<eatable[i].first<<" "<<eatable[i].second<<endl;
//
// cout<<"bigfish "<<bigfish.size()<<endl;
// for(int i=0; i<bigfish.size(); i++)
//   cout<<bigfish[i].second.first<<" "<<bigfish[i].second.second<<endl;
//
//   int a;
// cin>>a;
