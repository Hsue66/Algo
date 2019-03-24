//#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int main(){
  int testcase;
  scanf("%d%*c",&testcase);
  while(testcase--){
    int flag = 1;
    stack<char> S;
    char b;
    while(1){
      scanf("%c",&b);
      if(b == '\n')
        break;
      if(b == '[' || b == '{' || b == '(')
        S.push(b);
      else{
        int minus = 2;
        if(b == ')')
          minus = 1;

        if(!S.empty() && (S.top() == b-minus))
          S.pop();
        else
          flag = 0;
      }
    }
    if(!S.empty())
      flag = 0;

    if(flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
