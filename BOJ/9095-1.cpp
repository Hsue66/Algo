#include<cstdio>
//#include<iostream>
#define MAX 12

using namespace std;

int Mem[MAX]={0};

int main(){
  int testcase;
  scanf("%d",&testcase);

  Mem[1] = 1;
  Mem[2] = 2;
  Mem[3] = 4;
  int end = 4;
  while(testcase--){
    int Target;
    scanf("%d",&Target);

    if(Mem[Target] == 0){
      for(;end <=Target; end++)
        Mem[end] =  Mem[end-3]+Mem[end-2]+Mem[end-1];
    }
    printf("%d\n",Mem[Target]);
  }
}
