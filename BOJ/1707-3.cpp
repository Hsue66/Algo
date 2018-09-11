#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#define LIMIT 20001

using namespace std;

vector<vector<int> > G(LIMIT);
int group[LIMIT];
int wrong;

void bfs(int start){
  queue<int> Q;
  Q.push(start);
  group[start] = -1;

  while(!Q.empty()){
    int now = Q.front();
    Q.pop();
    int next = -1*group[now];
    for(int i=0; i<G[now].size(); i++){
      if(group[G[now][i]]){
        if(group[G[now][i]]!= next)
          wrong = 1;
      }
      else{
        group[G[now][i]] = next;
        Q.push(G[now][i]);
      }
    }
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  while(testcase--){
    int N,M;
    scanf("%d%d",&N,&M);
    while(M--){
      int s,t;
      scanf("%d%d",&s,&t);
      G[s-1].push_back(t-1);
      G[t-1].push_back(s-1);
    }

    fill_n(group,N, 0);
    wrong = 0;

    for(int i=0; i<N; i++){
      if(!group[i])
        bfs(i);
    }

    if(wrong)
      printf("NO\n");
    else
      printf("YES\n");

    for(int i=0; i<N; i++)
      G[i].clear();
  }
}
