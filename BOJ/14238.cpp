#include<iostream>
#include<cstdio>
#define LIMIT 51

using namespace std;

string S;
char Str[LIMIT];
int Cnt[3];
int N;
bool D[LIMIT][LIMIT][LIMIT][3][3];

bool check(int i, int a, int b, int c, int B1, int B2){
  if(N==i){
    if(a == Cnt[0] && b == Cnt[1] && c == Cnt[2])
      return true;
    else
      return false;
  }
  if(a > Cnt[0] || b > Cnt[1] || c > Cnt[2])
    return false;

  if(D[a][b][c][B1][B2]) return false;
  D[a][b][c][B1][B2] = true;

  Str[i] = 'A';
//  cout<<i<<" "<<Str[i]<<endl;
  if(check(i+1,a+1,b,c,0,B1)) return true;

  Str[i] = 'B';
//  cout<<i<<" "<<Str[i]<<endl;
  if(B1 != 1){
    if(check(i+1,a,b+1,c,1,B1)) return true;
  }

  Str[i] = 'C';
//  cout<<i<<" "<<Str[i]<<endl;
  if(B1 != 2 && B2 != 2){
    if(check(i+1,a,b,c+1,2,B1)) return true;
  }

  return false;
}

int main(){
  cin>>S;
  N = S.length();
  for(int i=0; i<N; i++)
    Cnt[S[i]-'A']++;

  if(check(0,0,0,0,0,0))
    printf("%s\n",Str );
  else
    printf("-1\n");
}
