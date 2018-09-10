#include<cstdio>
//#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
  int N,K;
  scanf("%d%d",&N,&K);
  vector<int> Num(N);
  for(int i=0; i<N; i++)
    scanf("%d",&Num[i]);

  nth_element(Num.begin(), Num.begin()+K-1, Num.end());

  printf("%d\n",Num[K-1]);
}
