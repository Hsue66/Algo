#include<stdio.h>

#include<iostream>
using namespace std;

#define MAX 10000
struct Elem{
  int x,y;
};

Elem Mats[MAX];
int eidx;
Elem buf[MAX];
int N;
int MAP[100][100];

void mergesort(Elem *p, int len){
  if(len<2) return;
  int i,j,k,mid;
  i = k = 0;
  j = mid = len/2;

  mergesort(p,mid);
  mergesort(p+mid,len-mid);

  while(i<mid && j<len){
    if(p[i].x*p[i].y < p[j].x*p[j].y)
      buf[k++] = p[i++];
    else if(p[i].x*p[i].y == p[j].x*p[j].y){
      if(p[i].x < p[j].x)
        buf[k++] = p[i++];
      else
        buf[k++] = p[j++];
    }
    else
      buf[k++] = p[j++];
  }

  while(i<mid)
    buf[k++] = p[i++];
  while(j<len)
    buf[k++] = p[j++];

  for(int i=0; i<len; i++)
    p[i] = buf[i];
}


struct Queue{
  Elem queue[MAX];
  int fidx,bidx;
  void init(){
    fidx = bidx = 0;
  }

  int empty(){
    return fidx==bidx;
  }

  void push(int x,int y){
    ++bidx;
    queue[bidx].x = x;
    queue[bidx].y = y;
  }

  void pop(){
    ++fidx;
  }

  Elem top(){
    return queue[fidx+1];
  }
};

int main(){
  int testcase;
  scanf("%d",&testcase);
  for(int tc=0; tc<testcase; tc++){
    scanf("%d",&N);
    Queue queue;
    queue.init();
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        scanf("%d",&MAP[i][j]);
        int flag = 1;
        if(MAP[i][j] != 0){
          if(0<=i-1 && MAP[i-1][j] != 0)
            flag = 0;
          if(0<=j-1 && MAP[i][j-1] != 0)
            flag = 0;
          if(flag)
            queue.push(i,j);
        }
      }
    }

    eidx = 0;
    while(!queue.empty()){
      Elem now = queue.top();
      queue.pop();
      int i, j;
      for(i=now.x+1; i<N && MAP[i][now.y] != 0; i++);
      for(j=now.y+1; j<N && MAP[now.x][j] != 0; j++);
      //cout<<i-now.x<<" "<<j-now.y<<endl;
      Mats[eidx].x = i-now.x;
      Mats[eidx].y = j-now.y;
      eidx++;
    }
    mergesort(Mats,eidx);

    printf("#%d %d",tc+1,eidx );
    for(int i=0; i<eidx; i++)
      printf(" %d %d",Mats[i].x,Mats[i].y );
    printf("\n");
  }
}
