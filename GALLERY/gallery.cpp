#include<iostream>
#include<cstdio>
#include<vector>
#define LIMIT 1001

using namespace std;

int G,H;
vector<int> Graph[LIMIT];
int visited[LIMIT];
int Min;
int Cnt;

void visit(){
  for(int i=0; i<G; i++){
    if(visited[i] == 0){
      visited[i] = 1;
      Cnt++;
      for(int j=0; j<Graph[i].size(); j++){
        if(visited[Graph[i][j]]==0)
          visited[Graph[i][j]]=1;
      }
    }
  }
  //cout<<Cnt<<endl;
  Min = min(Cnt,Min);
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  while(testcase--){
    scanf("%d%d",&G,&H );
    for(int i=0; i<H; i++){
      int s,t;
      scanf("%d%d",&s,&t );
      Graph[s].push_back(t);
      Graph[t].push_back(s);
    }

    Min = LIMIT;
    for(int i=0; i<G; i++){
      fill_n(visited,G,0);
      visited[i] = 1;
      Cnt = 1;
      for(int j=0; j<Graph[i].size(); j++)
        visited[Graph[i][j]] = 1;
      visit();
    }
    printf("%d\n",Min );
    for(int i=0; i<G; i++)
      Graph[i].clear();
  }
}
