#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<vector>

using namespace std;

map< pair<int,int>, int > All;
vector<vector<pair<int,int> > > Pre;
priority_queue<pair<int,pair<int,int> > > Breed;
vector<vector<pair<int,int> > > Active;
int N,M,K;
int Dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void showPre(){
  //cout<<"Pre----"<<endl;
  for(int i=0; i<11; i++){
    if(Pre[i].size() > 0){
      //cout<<endl;
      //cout<<i<<": ";
    }
    for(int j=0; j<Pre[i].size(); j++){
      //cout<<Pre[i][j].first<<", "<<Pre[i][j].second<<" ";
    }
  }
  //cout<<endl;
}

void showActive(){
  //cout<<"Active----"<<endl;
  for(int i=0; i<12; i++){
    if(Active[i].size() > 0){
      //cout<<endl;
      //cout<<i<<": ";
    }
    for(int j=0; j<Active[i].size(); j++){
      //cout<<Active[i][j].first<<", "<<Active[i][j].second<<" ";
    }
  }
  //cout<<endl;
}

void decreasePre(){
  vector<pair<int,int> > temp;
  Pre[0].swap(temp);
  for(int i=0; i<10; i++)
    Pre[i].swap(Pre[i+1]);

  Pre[0].swap(temp);
  if(temp.size() > 0){
    int size = temp.size();
    for(int i=0; i<size; i++){
      Active[All[temp[i]]+1].push_back(temp[i]);
      Breed.push(make_pair(All[temp[i]],temp[i]));
    }
  }
  //cout<<Breed.size()<<endl;
}

void decreaseActive(){
  vector<pair<int,int> > temp;
  Active[0].swap(temp);
  for(int i=0; i<11; i++)
    Active[i].swap(Active[i+1]);
  Active[0].swap(temp);
}

void breedCell(){
  while(!Breed.empty()){
    int x = Breed.top().second.first;
    int y = Breed.top().second.second;
    //cout<<x<<","<<y<<endl;
    for(int d=0; d<4; d++){
      int tx = x+Dir[d][0];
      int ty = y+Dir[d][1];
      if(All.find(make_pair(tx,ty)) == All.end()){
        All.insert(make_pair(make_pair(tx,ty),Breed.top().first));
        Pre[Breed.top().first+1].push_back(make_pair(tx,ty));
      }
    }
    Breed.pop();
  }
}

int countAlive(){
  int sum = 0;
  for(int i=1; i<11; i++)
    sum += Pre[i].size();
  for(int i=1; i<12; i++)
    sum += Active[i].size();
  return sum;
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d%d",&N,&M,&K );
    vector<vector<pair<int,int> > > pre(12);
    Pre.swap(pre);
    vector<vector<pair<int,int> > > active(12);
    Active.swap(active);
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        int t;
        scanf("%d",&t );
        if(t != 0){
          All.insert(make_pair(make_pair(i,j),t));
          Pre[t].push_back(make_pair(i,j));
        }
      }
    }

    int times =0;
    while(K--){
      // //cout<<++times<<"초---------------"<<endl;
      breedCell();
      decreasePre();
      decreaseActive();
      // showPre();
      // showActive();
      // char a;
      // cin>>a;
    }

    printf("#%d %d\n",t+1 ,countAlive());
    All.clear();
    Pre.clear();
    Active.clear();
    while(!Breed.empty())
      Breed.pop();
  }
}
