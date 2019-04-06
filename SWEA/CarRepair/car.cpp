#include<iostream>
#include<cstdio>
#include<queue>
#include<map>

using namespace std;

int K,A,B;
int N[2];
int Info[2][10];
int Room[2][10][2];
queue<int> waits[2];
queue<pair<int,int> > people;
map<int,int> cand;
int Acc,Cnt;

void makeEmpty(int idx){
  for(int i=0; i<N[idx]; i++){
    if(Room[idx][i][0] == Info[idx][i]){
      if(idx == 0 )
        waits[1].push(Room[idx][i][1]);
      Room[idx][i][0] = -1;
    }
  }
}

void fillNinc(int idx){
  for(int i=0; i<N[idx] && !waits[idx].empty(); i++){
    if(Room[idx][i][0] == -1){
      Room[idx][i][0] = 0;
      Room[idx][i][1] = waits[idx].front();
      Cnt++;
      if(idx == 0){
        if(i == A)
          cand.insert(make_pair(Room[idx][i][1],0));
      }else{
        if(i == B && cand.find(Room[idx][i][1]) != cand.end())
          Acc = Acc + Room[idx][i][1] +1;
      }
      waits[idx].pop();
    }
  }

  for(int i=0; i<N[idx]; i++){
    if(Room[idx][i][0] != -1)
      Room[idx][i][0]++;
    //cout<<Desk[i][1]<<" ";
  }
}

void find(){
  int now = people.front().first;
  while(1){
    makeEmpty(0);
    makeEmpty(1);

    while(people.front().first == now){
      waits[0].push(people.front().second);
      people.pop();
    }

    fillNinc(0);
    fillNinc(1);
    now++;
    if(Cnt == 2*K)
      break;
  }
}

void fill(int idx){
  for(int i=0; i<N[idx]; i++){
    scanf("%d",&Info[idx][i] );
    Room[idx][i][0] = -1;
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t =0; t<testcase; t++){
    scanf("%d%d%d%d%d",&N[0],&N[1],&K,&A,&B );

    fill(0);
    fill(1);
    for(int i=0; i<K; i++){
      int t;
      scanf("%d",&t );
      people.push(make_pair(t,i));
    }
    Acc = Cnt = 0;
    A--;
    B--;
    find();

    if(Acc == 0)
      Acc = -1;
    printf("#%d %d\n",t+1,Acc );
    cand.clear();
    //waits초기화하기
    for(int i=0; i<2; i++){
      while(!waits[i].empty())
        waits[i].pop();
    }
  }
}
