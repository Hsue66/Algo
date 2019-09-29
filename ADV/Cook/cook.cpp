#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N,Min;
int S[16][16];

int calc(int T[8]){
  int sum = 0;
  for(int i=0; i<N/2-1; i++){
    for(int j=i; j<N/2; j++){
      sum += S[T[i]][T[j]];
      sum += S[T[j]][T[i]];
    }
  }
  return sum;
}

void divGroup(){
  vector<int> p;
  for(int i=0; i<N/2; i++)
    p.push_back(0);
  for(int i=0; i<N/2; i++)
    p.push_back(1);
  sort(p.begin(),p.end());
  do{
    int A[8],B[8];
    int a,b;
    a = b = 0;
    for(int i=0; i<N; i++){
      if(p[i] == 0)
        A[a++] = i;
      else
        B[b++] = i;
    }
    Min = min(Min,abs(calc(A) - calc(B)));
  }while(next_permutation(p.begin(),p.end()));
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d",&N );
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++)
        scanf("%d",&S[i][j] );
    }

    Min = 987654321;
    divGroup();

    printf("#%d %d\n",t+1, Min );
  }
}
