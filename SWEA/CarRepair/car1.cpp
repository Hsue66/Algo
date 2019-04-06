#include<iostream>
#include<cstdio>
#include<queue>
#include<map>

using namespace std;

int N,M,K,A,B;
int Desk[10][2];
int Dinfo[10];
int Repair[10][2];
int Rinfo[10];
queue<pair<int,int> > people;
map<int,int> cand;
int Acc,Cnt;

void find(){
  int now = people.front().first;
  queue<int> dwaits,rwaits;
  while(1){
    //cout<<"now: "<<now<<endl;
    for(int i=0; i<N; i++){
      if(Desk[i][0] == Dinfo[i]){
        rwaits.push(Desk[i][1]);
        Desk[i][0] = -1;
      }
    }
    for(int i=0; i<M; i++){
      if(Repair[i][0] == Rinfo[i])
        Repair[i][0] = -1;
    }

    while(people.front().first == now){
      dwaits.push(people.front().second);
      people.pop();
    }
    for(int i=0; i<N && !dwaits.empty(); i++){
      if(Desk[i][0] == -1){
        Desk[i][0] = 0;
        Desk[i][1] = dwaits.front();
        if(i == A)
          cand.insert(make_pair(Desk[i][1],0));
        dwaits.pop();
      }
    }
    for(int i=0; i<M && !rwaits.empty(); i++){
      if(Repair[i][0] == -1){
        Repair[i][0] = 0;
        Repair[i][1] = rwaits.front();
        Cnt++;
        if(i == B && cand.find(Repair[i][1]) != cand.end())
          Acc = Acc + Repair[i][1] +1;
        rwaits.pop();
      }
    }
    //cout<<"D: ";
    for(int i=0; i<N; i++){
      if(Desk[i][0] != -1)
        Desk[i][0]++;
      //cout<<Desk[i][1]<<" ";
    }
    //cout<<endl;
    //cout<<"R: ";
    for(int i=0; i<M; i++){
      if(Repair[i][0] != -1)
        Repair[i][0]++;
      //cout<<Repair[i][1]<<" ";
    }
    now++;
    if(Cnt == K)
      break;
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t =0; t<testcase; t++){
    scanf("%d%d%d%d%d",&N,&M,&K,&A,&B );
    for(int i=0; i<N; i++){
      scanf("%d",&Dinfo[i] );
      Desk[i][0] = -1;
    }
    for(int i=0; i<M; i++){
      scanf("%d",&Rinfo[i] );
      Repair[i][0] = -1;
    }
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
  }
}
