#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;

int N,M,K;
vector<vector<int> > Micro;
int Dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
map<pair<int,int>,vector<int> > Pos;

void check(){
  vector<vector<int> > New;
  for(auto it = Pos.begin(); it!= Pos.end(); ++it){
    pair<int,int> loc = it->first;
    vector<int> mic = it->second;
    if(loc.first == 0 || loc.first == N-1 || loc.second == 0 || loc.second == N-1 ){   // boarder
      vector<int> temp(4);
      temp = Micro[mic[0]];
      temp[2] /= 2;
      temp[3] = (temp[3]+2)%4;
      // cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" "<<temp[3]<<" "<<endl;
      if(temp[2] != 0)
        New.push_back(temp);
    }else{
      int len = mic.size();
      vector<int> comb(4);
      comb = Micro[mic[0]];
      int before = comb[2];
      for(int i=1; i<len; i++){
        vector<int> temp(4);
        temp = Micro[mic[i]];
        if(before < temp[2]){
          comb[3] = temp[3];
          before = temp[2];
        }
        comb[2] += temp[2];
      }
      // cout<<comb[0]<<" "<<comb[1]<<" "<<comb[2]<<" "<<comb[3]<<" "<<endl;
      New.push_back(comb);
    }
  }
  Micro = New;
  K = Micro.size();
}

void moveAll(){
  for(int i=0; i<K; i++){
    int d = Micro[i][3];
    Micro[i][0] += Dir[d][0];
    Micro[i][1] += Dir[d][1];
    int x = Micro[i][0];
    int y = Micro[i][1];
    auto it = Pos.find(make_pair(x,y));
    if(it == Pos.end()){
      //not
      vector<int> temp(1);
      temp[0] = i;
      Pos.insert(make_pair(make_pair(x,y),temp));
    }else{
      //in
      vector<int> temp = it->second;
      temp.push_back(i);
      Pos[make_pair(x,y)] = temp;
    }
  }
}

int countAll(){
  int result = 0;
  for(int i=0; i<K; i++)
    result += Micro[i][2];
  return result;
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d%d",&N,&M,&K );
    for(int k=0; k<K; k++){
      vector<int> temp(4);
      scanf("%d%d%d%d",&temp[0],&temp[1],&temp[2],&temp[3] );
      temp[3] -= 1;
      if(temp[3] == 1)
        temp[3] = 2;
      else if(temp[3] == 2)
        temp[3] = 1;
      Micro.push_back(temp);
    }

    while(M--){
      moveAll();
      check();
      Pos.clear();
    }
    printf("#%d %d\n",t+1,countAll());
    Micro.clear();
  }
}
