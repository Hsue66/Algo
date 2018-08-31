#include<cstdio>
#include<iostream>
#define LIMIT 100001

using namespace std;

int S[2][LIMIT];
int main(){
  int testcase;
  scanf("%d",&testcase);
  while(testcase--){
    int len;
    scanf("%d",&len );

    for(int i=0; i<2; i++){
      for(int j=0; j<len; j++)
        scanf("%d",&S[i][j] );
    }

    int before[3] = {0};
    for(int i=0; i<len; i++){
      int S0 = max(before[1],before[2]) + S[0][i];
      int S1 = max(before[0],before[2]) + S[1][i];
      int No = max(before[2],max(before[0],before[1]));
      before[0] = S0;
      before[1] = S1;
      before[2] = No;
    }

    printf("%d\n",max(before[2],max(before[0],before[1])));
  }
}
