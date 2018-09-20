#include<cstdio>
#include<iostream>
#define LIMIT 1001

using namespace std;

int Link[LIMIT];
int visited[LIMIT];

void findCycle(int now){
  if(visited[now]){
    visited[now] = 0;
    findCycle(Link[now]-1);
  }
}

int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
      int N;
      scanf("%d",&N );
      fill_n(visited,N,1);
      for(int i=0; i<N; i++)
        scanf("%d",&Link[i]);

      int cnt = 0;
      for(int i=0; i<N; i++){
        if(visited[i]){
          visited[i] = 0;
          findCycle(Link[i]-1);
          cnt++;
        }
      }
      printf("%d\n",cnt);
    }
}
