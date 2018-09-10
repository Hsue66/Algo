#include<cstdio>
//#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int N;
  scanf("%d",&N );
  vector<pair<int,int> > Num;
  for(int i=0; i<N; i++){
    int n;
    scanf("%d",&n);
    Num.push_back(make_pair(n,i));
  }

  sort(Num.begin(), Num.end());

  int cnt = 0;
  for(int i=0; i<N; i++){
    if(cnt < Num[i].second - i)
      cnt = Num[i].second - i;
  }
  printf("%d\n",cnt+1);
}
