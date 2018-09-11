#include<cstdio>
//#include<iostream>
#include<queue>
#include<vector>
#define LIMIT 1001
using namespace std;

int visited[LIMIT] = {0};
vector<vector<int> > G(LIMIT);

void bfs(int start){
  queue<int> Q;
  Q.push(start);
  visited[start] = 1;

  while(!Q.empty()){
    int now = Q.front();
    Q.pop();
    for(int i=0; i<G[now].size(); i++){
      if(!visited[G[now][i]]){
        Q.push(G[now][i]);
        visited[G[now][i]] = 1;
      }
    }
  }
}
int main(){
  int N,M;
  scanf("%d%d",&N,&M);
  while(M--){
    int s,t;
    scanf("%d%d",&s,&t);
    G[s-1].push_back(t-1);
    G[t-1].push_back(s-1);
  }

  int cnt = 0;

  for(int i=0; i<N; i++){
    if(!visited[i]){
      bfs(i);
      cnt++;
    }
  }
  printf("%d\n",cnt );
}
