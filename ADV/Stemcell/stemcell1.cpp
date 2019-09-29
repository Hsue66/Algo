#include<iostream>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

map< pair<int,int>, int > All;
vector<vector<pair<int,int> > > Pre;
vector<vector<pair<int,int> > > Active;
int N,M,K;
int Dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void showPre(){
  cout<<"---Pre----"<<endl;
  for(int i=1; i<11; i++){
    if(Pre[i].size() > 0){
      cout<<endl;
      cout<<i<<": ";
    }
    for(int j=0; j<Pre[i].size(); j++){
      cout<<Pre[i][j].first<<", "<<Pre[i][j].second<<" ";
    }
  }
  cout<<endl;
}
void showActive(){
  cout<<"---Active----"<<endl;
  for(int i=1; i<12; i++){
    if(Active[i].size() > 0){
      cout<<endl;
      cout<<i<<": ";
    }
    for(int j=0; j<Active[i].size(); j++){
      cout<<Active[i][j].first<<", "<<Active[i][j].second<<" ";
    }
  }
  cout<<endl;
}
void decreasePre(){
  vector<pair<int,int> > temp;
  for(int i=0; i<10; i++)
    Pre[i].swap(Pre[i+1]);
  Pre[10].swap(temp);
  if(temp.size() > 0){
    int size = temp.size();
    for(int i=0; i<size; i++)
      Active[All[temp[i]]+1].push_back(temp[i]);
  }
}

void decreaseActive(){
  map< pair<int,int>, int > New;
  vector<pair<int,int> > temp;
  Active[0].swap(temp);
  for(int i=1; i<12; i++){
    int size = Active[i].size();
    for(int j=0; j<size; j++){
      if(All[Active[i][j]] == i){
        int x = Active[i][j].first;
        int y = Active[i][j].second;
        for(int d=0; d<4; d++){
          int tx = x+Dir[d][0];
          int ty = y+Dir[d][1];
          if(All.find(make_pair(tx,ty)) == All.end()){ // All에 없음
            if(New.find(make_pair(tx,ty)) == New.end())
              New.insert(make_pair(make_pair(tx,ty),i));
            else{
              if(New[make_pair(tx,ty)] < i)
                New[make_pair(tx,ty)] = i;
            }
          }
        }
      }
    }
    // Active[i-1] = Active[i];
  }
  for(int i=1; i<12; i++)
    Active[i].swap(Active[i-1]);

  for(auto it=New.begin(); it!=New.end(); ++it){
    All.insert(make_pair(it->first,it->second));
    Pre[it->second].push_back(it->first);
  }
}

int countAlive(){
  int Cnt = 0;
  for(int i=1; i<11; i++){
    int size = Pre[i].size();
    if(size > 0)
      Cnt += size;
  }
  for(int i=1; i<12; i++){
    int size = Active[i].size();
    if(size > 0)
      Cnt += size;
  }
  return Cnt;
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d%d",&N,&M,&K );
    vector<vector<pair<int,int> > > pre(11);
    Pre = pre;
    vector<vector<pair<int,int> > > active(12);
    Active = active;
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

    int time=0;
    while(K--){
      // cout<<++time<<"초 ------------"<<endl;
      decreasePre();
      decreaseActive();
      // showPre();
      // showActive();
      // char a;
      // cin>>a;
    }
    printf("#%d %d\n",t+1,countAlive() );
    All.clear();
    Pre.clear();
    Active.clear();
  }
}
