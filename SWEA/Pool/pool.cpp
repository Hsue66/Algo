#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int Price[4];
int Values[12];
int minCost;
int Three[12][3];

void calcThree(){
  Three[0][1] = Three[0][2] = Three[0][0] = Values[0];
  Three[1][1] = Three[1][2] = Price[2];
  Three[1][0] = Values[1] + Values[0];

  for(int n=2; n<12; n++){
    // [0]
    Three[n][0] = Values[n] + min(min(Three[n-1][0],Three[n-1][1]),Three[n-1][2]);
    // [1]
    Three[n][1] = Three[n-1][2];
    //[2]
    Three[n][2] = min(min(Three[n-2][0],Three[n-2][1]),Three[n-2][2])+Price[2];
  }

  minCost = min(minCost, min(min(Three[11][0],Three[11][1]),Three[11][2]));
}

int main(){
  int testcase;
  scanf("%d",&testcase );

  for(int i=1; i<=testcase; i++){
    // prices
    for(int j=0; j<4; j++)
      scanf("%d",&Price[j]);
    minCost = Price[3];

    // days
    int acc = 0;
    for(int j=0; j<12; j++){
      int value;
      scanf("%d",&value);
      Values[j] = value*Price[0];
      if(Values[j] > Price[1])
        Values[j] = Price[1];
      acc += Values[j];
      if(Values[j] > Price[2])
        Values[j] = Price[2];
    }
    if(acc < minCost)
      minCost = acc;

    // three months
    calcThree();

    printf("#%d %d\n",i,minCost);
  }
}
