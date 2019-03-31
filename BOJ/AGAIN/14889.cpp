#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> p;
int N,Min;
int MAP[20][20];

int calc(int T[10]){
  int temp = 0;
  for(int i=0; i<(N/2)-1; i++){
    for(int j=i+1; j<N/2; j++){
      temp += MAP[T[i]][T[j]];
      temp += MAP[T[j]][T[i]];
    }
  }
  return temp;
}

int main(){
  scanf("%d",&N );
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      scanf("%d",&MAP[i][j] );
  }

  for(int i=0; i<N/2; i++)
    p.push_back(1);
  for(int i=0; i<N/2; i++)
    p.push_back(0);

  sort(p.begin(), p.end());
  Min = 987654321;
  do{
    int aIdx,bIdx;
    aIdx = bIdx = 0;
    int A[10],B[10];
    for(int i=0; i<N; i++){
      if(p[i] == 0)
        A[aIdx++] = i;
      else
        B[bIdx++] = i;
    }
    Min = min(Min,abs(calc(A)-calc(B)));
  }while(next_permutation(p.begin(), p.end()));

  printf("%d\n",Min );
}
