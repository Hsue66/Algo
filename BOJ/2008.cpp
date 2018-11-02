#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAX 987654321

using namespace std;

int N,M,DEL,ADD,a,b;
int LADDER[502];
int D[502][101];

void find(){
  for(int j = 0; j<N; j++){
    if(j==a)
      D[0][j] = 0;
    else
      D[0][j] = abs(j-a)*ADD;
  }

  for(int i=1; i<=M; i++){
    for(int k=0; k<N; k++){
      for(int j=0; j<N; j++){
        if(j==k && ( LADDER[i] == k || LADDER[i]+1 == k)){
          if(D[i][j] > D[i-1][j] + DEL)
            D[i][j] = D[i-1][j] + DEL;
        }
        else if((k <= LADDER[i] && LADDER[i] <= j-1) || (j <= LADDER[i] && LADDER[i] <= k-1)){
          if(D[i][j] > D[i-1][k] + (abs(k-j)-1)*ADD)
            D[i][j] = D[i-1][k] + (abs(k-j)-1)*ADD;
        }
        else{
          if(D[i][j] > D[i-1][k] + abs(k-j)*ADD)
            D[i][j] = D[i-1][k] + abs(k-j)*ADD;
        }
      }
    }
  }
}

int main(){
  scanf("%d%d",&N,&M);
  for(int i=0; i<=M; i++)
    fill_n(D[i], N, MAX);

  scanf("%d%d%d%d",&a,&b,&DEL,&ADD);
  for(int i=1; i<=M; i++){
    scanf("%d",&LADDER[i]);
    LADDER[i] -= 1;
  }
  a = a-1;
  b = b-1;
  find();
  printf("%d\n",D[M][b]);
}
