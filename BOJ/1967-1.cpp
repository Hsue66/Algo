#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define MAX 10001
using namespace std;

vector<pair<int,int> > Tree[MAX];

int mIdx=0;
int mVal=0;
int visited[MAX] = {0};

void bfs(int node){
  queue<pair<int,int> > Q;
  Q.push(make_pair(node,0));
  visited[node] = 1;
  while(!Q.empty()){
    int s = Q.front().first;
    int v = Q.front().second;
    Q.pop();
    for(int i=0; i<Tree[s].size(); i++){
      if(visited[Tree[s][i].first] == 0){
        int temp = v+Tree[s][i].second;
        if(mVal < temp){
          mVal = temp;
          mIdx = Tree[s][i].first;
        }
        Q.push(make_pair(Tree[s][i].first, temp));
        visited[Tree[s][i].first] = 1;
      }
    }
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1; i<N; i++){
    int s,t,v;
    scanf("%d%d%d",&s,&t,&v);
    Tree[s-1].push_back(make_pair(t-1,v));
    Tree[t-1].push_back(make_pair(s-1,v));
  }

  bfs(0);
  mVal = 0;
  fill_n(visited,N,0);
  bfs(mIdx);
  printf("%d\n",mVal);
}
