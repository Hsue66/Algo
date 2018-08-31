#include<cstdio>
//#include<iostream>
#define MAX 1002
using namespace std;

int Memo[MAX];
int main(){
  Memo[1] = 1;
  Memo[2] = 2;
  Memo[3] = 3;
  int Target;
  scanf("%d",&Target );

  for(int num = 4; num<=Target; num++)
    Memo[num] = (Memo[num-2]+Memo[num-1])% 10007;

  printf("%d\n",Memo[Target]);
}
