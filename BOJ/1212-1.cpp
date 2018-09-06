#include<cstdio>
//#include<iostream>
#include<stack>

using namespace std;

stack<int> str;
stack<int> nStr;

int main(){
  char c;
  while(scanf("%c",&c)==1){
    if(c == '\n')
      break;
    str.push(c-'0');
  }

  while(!str.empty()){
    int val = str.top();
    str.pop();
    int cnt = 0;
    while(val){
      nStr.push(val%2);
      val = val/2;
      cnt++;
    }
    while(cnt++<3)
      nStr.push(0);
  }

  int flag = 0;
  while(!nStr.empty()){
    if(nStr.top())
      flag = 1;
    if(flag)
      printf("%d",nStr.top());
    nStr.pop();
  }
  if(flag==0)
    printf("0");
  printf("\n");
}
