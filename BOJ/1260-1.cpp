#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#define LIMIT 1001

using namespace std;

vector<vector<int> > G(LIMIT);
int visited[LIMIT] = {0};

void bfs(int start){
  queue<int> Q;
  Q.push(start);
  visited[start] = 1;

  while(!Q.empty()){
    int now =  Q.front();
    printf("%d ",now+1);
    Q.pop();
    for(int i=0; i<G[now].size(); i++){
      if(!visited[G[now][i]]){
        Q.push(G[now][i]);
        visited[G[now][i]] = 1;
      }
    }
  }
}

void dfs(int start){
  stack<int> S;
  S.push(start);
  visited[start] = 1;
  printf("%d ",start+1);

  while(!S.empty()){
    int now = S.top();

    int flag = 1;
    for(int i=0; i<G[now].size(); i++){
      if(!visited[G[now][i]]){
        S.push(G[now][i]);
        visited[G[now][i]] = 1;
        printf("%d ",G[now][i]+1);
        flag = 0;
        break;
      }
    }
    if(flag)
      S.pop();
  }
}
int main(){
  int N,M,start;
  scanf("%d%d%d",&N,&M,&start);

  while(M--){
    int s,t;
    scanf("%d%d",&s,&t );
    G[s-1].push_back(t-1);
    G[t-1].push_back(s-1);
  }

  for(int i=0; i<N; i++)
    sort(G[i].begin(), G[i].end());

  dfs(start-1);
  printf("\n");
  fill_n(visited,N,0);
  bfs(start-1);
  printf("\n");
}
