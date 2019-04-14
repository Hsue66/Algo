#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int MAP[10][10],A[10][10];
int N,M,K;
int Dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
map< pair<int,int>, vector<int> > Trees;
map< pair<int,int>, int > New;

void breed(){
  for(auto it=New.begin(); it!=New.end(); ++it){
    int cnt = (*it).second;
    if(Trees.find((*it).first) == Trees.end()){
      vector<int> v;
      for(int i=0; i<cnt; i++)
        v.push_back(1);
      Trees.insert(make_pair((*it).first,v));
    }else{
      for(int i=0; i<cnt; i++)
        Trees[(*it).first].push_back(1);
      sort(Trees[(*it).first].begin(),Trees[(*it).first].end());
    }
  }
  New.clear();
}

void passSS(){
  int size = Trees.size();
  for(auto it=Trees.begin(); it!=Trees.end(); ++it){
    int dead = 0;
    int x = (*it).first.first;
    int y = (*it).first.second;
    vector<int> T = (*it).second;
    vector<int> Left;
    int len = T.size();
    for(int i=0; i<len; i++){
      if(MAP[x][y] - T[i] < 0)
        dead += (T[i]/2);
      else{
        MAP[x][y] -= T[i];
        Left.push_back(T[i]+1);
        if((T[i]+1)%5 == 0){
          for(int d=0; d<8; d++){
            int tx = x+Dir[d][0];
            int ty = y+Dir[d][1];
            if(0<= tx && tx <N && 0<= ty && ty <N ){
              if(New.find(make_pair(tx,ty)) != New.end())
                New[make_pair(tx,ty)]++;
              else
                New.insert(make_pair(make_pair(tx,ty),1));
            }
          }
        }
      }
    }
    (*it).second = Left;
    MAP[x][y] += dead;
  }
}

void Timepass(){
  passSS();
  breed();
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      MAP[i][j] += A[i][j];
  }
}

int count(){
  int sum = 0;
  for(auto it=Trees.begin(); it!= Trees.end(); ++it)
    sum += (*it).second.size();
  return sum;
}

int main(){
  scanf("%d%d%d",&N,&M,&K );
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      scanf("%d",&A[i][j] );
  }
  for(int i=0; i<N; i++)
    fill_n(MAP[i],N,5);
  while(M--){
    int x,y;
    vector<int> v(1);
    scanf("%d%d%d",&x,&y,&v[0] );
    Trees.insert(make_pair(make_pair(x-1,y-1),v));
  }

  while(K--)
    Timepass();

  printf("%d\n",count() );
}
