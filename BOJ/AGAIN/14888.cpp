#include<iostream>
#include<cstdio>

using namespace std;

int N,Min,Max;
int Num[12];
int Op[4] = {0};

void calc(int before, int idx){
  if(idx == N){
    Min = min(Min, before);
    Max = max(Max, before);
  }
  for(int i=0; i<4; i++){
    if(Op[i] > 0){
      int temp = before;
      if(i == 0)
        temp += Num[idx];
      else if( i == 1)
        temp -= Num[idx];
      else if(i == 2)
        temp *= Num[idx];
      else
        temp /= Num[idx];
      Op[i]--;
      calc(temp, idx+1);
      Op[i]++;
    }
  }
}

int main(){
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    scanf("%d",&Num[i] );
  for(int i=0; i<4; i++)
    scanf("%d",&Op[i] );

  Min = 1987654321;
  Max = -1987654321;
  calc(Num[0],1);
  printf("%d\n", Max);
  printf("%d\n", Min);
}
