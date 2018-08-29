#include<cstdio>
#include<queue>

using namespace std;

queue<int> circleQ;

int main(){
  int N, M;
  scanf("%d %d",&N,&M );

  for(int i=0; i<N; i++)
    circleQ.push(i+1);

  int cnt = 1;
  int flag = 0;
  printf("<");
  while(!circleQ.empty()){
    if(cnt == M){
      if(flag)
        printf(", ");
      cnt = 1;
      printf("%d",circleQ.front());
      circleQ.pop();
      flag = 1;
    }
    else{
      cnt++;
      circleQ.push(circleQ.front());
      circleQ.pop();
    }
  }
  printf(">\n");
}
