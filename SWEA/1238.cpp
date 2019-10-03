#include<stdio.h>

#define MAX 102

int MAP[MAX][MAX];
int visited[MAX];

struct Queue{
  int node[MAX];
  int fIdx;
  int bIdx;
  Queue(){
    bIdx = fIdx =0;
  }
  void push(int v){
    node[bIdx++] = v;
  }
  void pop(){
    fIdx++;
  }
  int front(){
    return node[fIdx];
  }
  int empty(){
    return bIdx == fIdx;
  }
};


void init(){
  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++)
      MAP[i][j] = 0;
    visited[i] = 0;
  }
}

int main(){
  for(int t=0; t<10; t++){
    int n, start;
    scanf("%d%d",&n,&start );
    init();
    for(int i=0; i<n/2; i++){
      int s,t;
      scanf("%d%d",&s,&t );
      MAP[s][t] = 1;
    }
    Queue queue;
    queue.push(start);
    visited[start] = 1;

    int last=0, lastIdx = 0;
    while(!queue.empty()){
      int now = queue.front();
      queue.pop();
      for(int i=0; i<MAX; i++){
        if(MAP[now][i] == 1 && visited[i] == 0){
          visited[i] = visited[now]+1;

          if(last<visited[i] || (last == visited[i] && lastIdx < i)){
            last = visited[i];
            lastIdx = i;
          }
          queue.push(i);
        }
      }
    }

    printf("#%d %d\n",t+1, lastIdx);
  }
}
