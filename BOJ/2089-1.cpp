#include<cstdio>
//#include<iostream>
#include<stack>

using namespace std;

stack<int> S;
int main(){
  int N;
  scanf("%d",&N );

  do{
    if(N>0){
      S.push(N%-2);
      N= N/-2;
    }else{
      int left = N%-2;
      int n = N/-2;
      if(left < 0){
        left = 1;
        n++;
      }
      S.push(left);
      N= n;
    }
  }while(N);

  while(!S.empty()){
    printf("%d",S.top());
    S.pop();
  }
  printf("\n");
}
