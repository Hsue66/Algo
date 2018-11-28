//#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>

using namespace std;

stack<int> Post;

void makePost(queue<int> P, queue<int> I){
  Post.push(P.front());
  int root = P.front(); P.pop();
  queue<int> Pleft,Ileft;
  while(I.front() != root){
    Ileft.push(I.front());  I.pop();
    Pleft.push(P.front());  P.pop();
  }
  I.pop();

  if(!P.empty() || !I.empty())
    makePost(P,I);
  if(!Pleft.empty() || !Ileft.empty())
    makePost(Pleft,Ileft);
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  while(testcase--){
    int len,temp;
    scanf("%d",&len);

    queue<int> Pre;
    queue<int> In;
    for(int i=0; i<len; i++){
      scanf("%d",&temp);
      Pre.push(temp);
    }
    for(int i=0; i<len; i++){
      scanf("%d",&temp);
      In.push(temp);
    }
    makePost(Pre,In);
    while(!Post.empty()){
      printf("%d ",Post.top());
      Post.pop();
    }
    printf("\n");
  }
}
