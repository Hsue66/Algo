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
  findNum();
}

int main(){
  All.insert(10);
  All.insert(12);
  All.insert(0);
  All.insert(3);

  for(auto it=All.begin(); it!=All.end(); ++it)
    cout<<*it<<" ";
    cout<<endl;
}
