//#include<iostream>
#include<cstdio>
#define LIMIT 31

using namespace std;

int N, K;
bool D[LIMIT][LIMIT][LIMIT][LIMIT*(LIMIT-1)/2];
char Str[LIMIT];

bool check(int i, int a, int b, int p){
  if(i == N){
    if(p == K)
      return true;
    else
      return false;
  }

  if(D[i][a][b][p])
    return false;
  D[i][a][b][p] = true;

  Str[i] = 'A';
  if(check(i+1,a+1,b,p)) return true;
  Str[i] = 'B';
  if(check(i+1,a,b+1,p+a)) return true;
  Str[i] = 'C';
  if(check(i+1,a,b,p+a+b)) return true;

  return false;
}

int main(){
  scanf("%d%d",&N, &K);
  if(check(0,0,0,0))
    printf("%s\n",Str);
  else
    printf("-1\n");
}
