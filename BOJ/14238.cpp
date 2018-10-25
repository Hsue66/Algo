#include<iostream>
#include<cstdio>
#define LIMIT 51

using namespace std;

string S;
char Str[LIMIT];
int Cnt[3];
int N;
bool D[LIMIT][3][LIMIT][LIMIT][LIMIT];

bool check(int i, int before, int a, int b, int c){
  if(N==i){
    if(a == Cnt[0] && b == Cnt[1] && c == Cnt[2])
      return true;
    else
      return false;
  }
  if(a > Cnt[0] || b > Cnt[1] || c > Cnt[2])
    return false;

  if(D[i][before][a][b][c]) return false;
  D[i][before][a][b][c] = true;

  Str[i] = 'A';
  if(check(i+1,0,a+1,b,c)) return true;

  Str[i] = 'B';
  if(!(0 <= i-1 && Str[i-1] == 'B')){
    if(check(i+1,1,a,b+1,c)) return true;
  }

  Str[i] = 'C';
  if(!((0 <= i-1 && Str[i-1] == 'C') || (0 <= i-2 && Str[i-2] == 'C'))){
    if(check(i+1,2,a,b,c+1)) return true;
  }

  return false;
}

int main(){
  cin>>S;
  N = S.length();
  for(int i=0; i<N; i++)
    Cnt[S[i]-'A']++;

  if(check(0,0,0,0,0))
    printf("%s\n",Str );
  else
    printf("-1\n");
}
