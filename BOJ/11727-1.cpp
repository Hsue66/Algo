#include<cstdio>
//#include<iostream>
#define MAX 1002
using namespace std;

int Mem[MAX];
int main(){
  Mem[1] = 1;
  Mem[2] = 3;
  int Target;
  scanf("%d",&Target);

  for(int num=3; num<=Target; num++)
    Mem[num] = (Mem[num-1] + 2*Mem[num-2])%10007;

  printf("%d\n",Mem[Target]);
}
