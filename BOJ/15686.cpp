//#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#define C_LIMIT 14
#define H_LIMIT 101

using namespace std;

int N,M;
int MIN=987654321;
vector<pair<int,int> > House;
vector<pair<int,int> > Chicken;
int dist[C_LIMIT][H_LIMIT];

void calcDist(){
  for(int i=0; i<Chicken.size(); i++){
    for(int j=0; j<House.size(); j++)
      dist[i][j] = abs(Chicken[i].first-House[j].first) + abs(Chicken[i].second-House[j].second);
  }
}

void findPair(int source[H_LIMIT], int next, int cnt){
  if(cnt == M){
    int sum = 0;
    for(int i=0; i<House.size(); i++)
      sum += source[i];
    MIN = min(sum, MIN);
  }
  else if(cnt < M){
    for(int i=next; i<Chicken.size(); i++){
      if(Chicken.size()-i > M-cnt-1){
        int temp[H_LIMIT];
        copy(source,source+House.size(),temp);
        for(int t=0; t<House.size(); t++)
          temp[t] = min(temp[t],dist[i][t]);

        findPair(temp, i+1, cnt+1);
      }
    }
  }
}

int main(){
  scanf("%d%d",&N,&M);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      int t;
      scanf("%d",&t);
      if(t==1)
        House.push_back(make_pair(i,j));
      else if(t==2)
        Chicken.push_back(make_pair(i,j));
    }
  }

  calcDist();

  int now[H_LIMIT];
  for(int c=0; c<Chicken.size(); c++){
    for(int i=0; i<House.size(); i++)
      now[i] = dist[c][i];
    findPair(now,c+1,1);
  }
  printf("%d\n",MIN );
}
