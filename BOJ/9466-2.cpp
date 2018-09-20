#include<cstdio>
#include<iostream>
#include<stack>
#define LIMIT 100001

using namespace std;

int visited[LIMIT];
int Link[LIMIT];
int Sum;
stack<int> S;

void findTeam(int now, int cnt){
  S.push(now);
  if(visited[now]==0){
    visited[now] = ++cnt;
    findTeam(Link[now]-1,cnt);
  }
  else if(visited[now] != -1)
    Sum = Sum + cnt+1 - visited[now];
}

int main(){
  int testcase;
  scanf("%d",&testcase);
  while(testcase--){
    int N;
    scanf("%d",&N);
    fill_n(visited,N,0);
    for(int i=0; i<N; i++)
      scanf("%d",&Link[i]);

    Sum = 0;
    for(int i=0; i<N; i++){
      if(visited[i] == 0){
        visited[i] = 1;
        findTeam(Link[i]-1,1);
        visited[i] = -1;
        while(!S.empty()){
          visited[S.top()] = -1;
          S.pop();
        }
      }
    }
    printf("%d\n",N-Sum);
  }
}
