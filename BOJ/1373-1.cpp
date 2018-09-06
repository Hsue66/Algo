#include<cstdio>
//#include<iostream>
#include<stack>

using namespace std;

stack<int> S;

int main(){
  char n;
  long long sum=0;
  while(scanf("%c",&n) == 1){
    if(n == '\n')
      break;
    sum = sum*2 + (n-'0');
  }
  
  if(sum == 0)
    S.push(sum);
  while(sum){
    S.push(sum%8);
    sum = sum/8;
  }

  while(!S.empty()){
    printf("%d",S.top() );
    S.pop();
  }
  printf("\n");
}
