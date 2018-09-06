#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  int testcase;
  scanf("%d",&testcase );
  while(testcase--){
    int A,B;
    scanf("%d%d",&A,&B);
    int big = max(A,B);
    int small = min(A,B);

    while(small != 0){
      int t = big % small;
      big = small;
      small = t;
    }
    printf("%d\n",A*B/big );
  }
}
