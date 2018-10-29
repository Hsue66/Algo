#include<iostream>
#include<cstdio>
#define MAX 987654321

using namespace std;

int D[61][61][61];
int N;
int cases[6][3] = {{-9,-3,-1},{-9,-1,-3},{-3,-9,-1},{-3,-1,-9},{-1,-9,-3},{-1,-3,-9}};

void findMin(int n[3]){
  for(int i=0; i<6; i++){
    int temp[3] = {0};
    for(int t=0; t<N; t++)
      temp[t] = n[t]+cases[i][t] > 0 ? n[t]+cases[i][t] : 0;

    if(D[temp[0]][temp[1]][temp[2]] == 0){
      D[temp[0]][temp[1]][temp[2]] = MAX;
      findMin(temp);
    }

    D[n[0]][n[1]][n[2]] = min(D[temp[0]][temp[1]][temp[2]]+1, D[n[0]][n[1]][n[2]]);
  }
}

int main(){
  D[0][0][0] = 1;
  scanf("%d",&N);
  int num[3] = {0};
  for(int i=0; i<N; i++)
    scanf("%d",&num[i]);
  D[num[0]][num[1]][num[2]] = MAX;
  findMin(num);
  printf("%d\n",D[num[0]][num[1]][num[2]]-1);
}
