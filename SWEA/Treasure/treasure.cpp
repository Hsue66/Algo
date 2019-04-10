#include<iostream>
#include<cstdio>
#include<deque>
#include<set>

using namespace std;

int N,K;
deque<int> Num;
set<int, greater<int> > All;

void findNum(){
  for(int i=0; i<4; i++){
    int idx = i*N/4;
    int sum = 0;
    for(int j=0; j<N/4; j++)
      sum = sum*16 + Num[idx+j];
    All.insert(sum);
  }
}
void findAll(){
  for(int i=0; i<N/4; i++){
    findNum();
    Num.push_front(Num.back());
    Num.pop_back();
  }
}

int main(){
  int testcase;
  scanf("%d%*c",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d%*c",&N,&K );
    for(int i=0; i<N; i++){
      char temp;
      scanf("%c",&temp );
      if('A'<= temp && temp <= 'F')
        Num.push_back(temp-'A'+10);
      else
        Num.push_back(temp-'0');
    }

    findAll();
    int i = 0;
    int res;
    res = *next(All.begin(),K-1);
    // for(auto it=All.begin(); it!=All.end() &&  i<K; ++it,i++){
    //   if(i == K-1)
    //     res = *it;
    // }
    printf("#%d %d\n",t+1,res );
    All.clear();
    Num.clear();
  }
}
