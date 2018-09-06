#include<cstdio>
//#include<iostream>
#include<cmath>
#include<vector>
#include<stack>

using namespace std;

vector<int> str;
stack<int> nStr;

int main(){
  char n;
  while(scanf("%c",&n) == 1){
    if(n == '\n')
      break;
    str.push_back(n-'0');
  }

  int cnt = 0;
  int subSum = 0;
  while(!str.empty()){
    if(cnt == 3){
      nStr.push(subSum);
      cnt =0;
      subSum = 0;
    }
    subSum = subSum + str.back()*pow(2,cnt++);
    str.pop_back();
  }
  nStr.push(subSum);

  while(!nStr.empty()){
    printf("%d",nStr.top());
    nStr.pop();
  }
  printf("\n");
}
