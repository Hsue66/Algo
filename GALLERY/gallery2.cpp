#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#define LIMIT 1001

using namespace std;

int G,H;
vector<int> Graph[LIMIT];
stack<int> S;
int visited[LIMIT];
int Min;

void dfs(){
  int now = S.top();
  for(int i=0; i<Graph[now].size(); i++){
    if(visited[Graph[now][i]] == 0){
      visited[Graph[now][i]] = -1*visited[now];
      S.push(Graph[now][i]);
      dfs();
    }
  }
  S.pop();
}

int check(){
  int Cnt1 = 0;
  for(int i=0; i<G; i++){
    if(visited[i] == 1)
      Cnt1++;
    if(visited[i] == 0)
      return i;
  }
  Min = min(Cnt1,Min);
  return -1;
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

    for(int i=0; i<G; i++){
      Min = 987654321;
      fill_n(visited,G,0);
      int now = i;
      do{
        visited[now] = 1;
        S.push(now);
        dfs();
        now = check();
      }while(now!=-1);
    }

    printf("%d\n",Min );
    for(int i=0; i<G; i++)
      Graph[i].clear();
  }
}
