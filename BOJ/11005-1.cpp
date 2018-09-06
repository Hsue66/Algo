#include<cstdio>
//#include<iostream>
#include<stack>

using namespace std;

stack<int> S;
int main(){
  int N,B;
  scanf("%d%d",&N,&B);

  while(N){
    S.push(N%B);
    N = N/B;
  }

  while(!S.empty()){
    int val = S.top();
    S.pop();
    if(val > 9)
      val = val-10+'A';
    else
      val = val + '0';
    printf("%c",val);
  }
  printf("\n");
}
