#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define MAX 100001
using namespace std;

vector<vector<pair<int,int> > > Tree(MAX);

int mIdx=0;
long long mVal=0;
int visited[MAX] = {0};

void bfs(int node){
  queue<pair<int,long long> > Q;
  Q.push(make_pair(node,0));
  visited[node] = 1;
  while(!Q.empty()){
    int s = Q.front().first;
    long long v = Q.front().second;
    Q.pop();
    for(int i=0; i<Tree[s].size(); i++){
      if(visited[Tree[s][i].first] == 0){
        long long temp = v+Tree[s][i].second;
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
  for(int i=0; i<N; i++){
    int s,t,v;
    scanf("%d",&s);
    while(1){
      scanf("%d",&t);
      if(t == -1)
        break;
      scanf("%d",&v);
      Tree[s-1].push_back(make_pair(t-1,v));
    }
  }

  bfs(0);
  mVal = 0;
  fill_n(visited,N,0);
  bfs(mIdx);
  printf("%lld\n",mVal );
}
