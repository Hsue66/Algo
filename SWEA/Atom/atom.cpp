#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>

using namespace std;
vector<vector<int> > Atom;
multimap<double,pair<int,int> > Collapse;
int AIdx[1000];
int N,Total;

void check(){
  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      if(Atom[i][0] == Atom[j][0]){
        if((Atom[i][1] <= Atom[j][1] && Atom[i][2] == 0 && Atom[j][2] == 1) || (Atom[j][1] <= Atom[i][1] && Atom[j][2] == 0 && Atom[i][2] == 1))
           Collapse.insert(make_pair(abs(Atom[i][1]-Atom[j][1])/2.0,make_pair(i,j)));
      }
      else if(Atom[i][1] == Atom[j][1]){
        if((Atom[i][0] <= Atom[j][0] && Atom[i][2] == 3 && Atom[j][2] == 2) || (Atom[j][0] <= Atom[i][0] && Atom[j][2] == 3 && Atom[i][2] == 2))
           Collapse.insert(make_pair(abs(Atom[i][0]-Atom[j][0])/2.0,make_pair(i,j)));
      }
      else if(abs(Atom[i][0]-Atom[j][0]) == abs(Atom[i][1]-Atom[j][1])){
        if((Atom[i][2] == 3 && Atom[j][2] == 0 && Atom[i][0] <= Atom[j][0] && Atom[i][1] >= Atom[j][1]) ||
        (Atom[i][2] == 0 && Atom[j][2] == 2 && Atom[i][0] <= Atom[j][0] && Atom[i][1] <= Atom[j][1]) ||
        (Atom[i][2] == 2 && Atom[j][2] == 1 && Atom[i][0] >= Atom[j][0] && Atom[i][1] <= Atom[j][1]) ||
        (Atom[i][2] == 1 && Atom[j][2] == 3 && Atom[i][0] >= Atom[j][0] && Atom[i][1] >= Atom[j][1]) ||
        (Atom[i][2] == 0 && Atom[j][2] == 3 && Atom[i][0] >= Atom[j][0] && Atom[i][1] <= Atom[j][1]) ||
        (Atom[i][2] == 2 && Atom[j][2] == 0 && Atom[i][0] >= Atom[j][0] && Atom[i][1] >= Atom[j][1]) ||
        (Atom[i][2] == 1 && Atom[j][2] == 2 && Atom[i][0] <= Atom[j][0] && Atom[i][1] >= Atom[j][1]) ||
        (Atom[i][2] == 3 && Atom[j][2] == 1 && Atom[i][0] <= Atom[j][0] && Atom[i][1] <= Atom[j][1]))
          Collapse.insert(make_pair(abs(Atom[i][0]-Atom[j][0]),make_pair(i,j)));
      }
    }
  }
}

void erase(){
  while(!Collapse.empty()){
    double t;
    int x,y;
    do{
      while(!Collapse.empty()){
        t = Collapse.begin()->first;
        x = Collapse.begin()->second.first;
        y = Collapse.begin()->second.second;
        if(AIdx[x]==1 || AIdx[y]==1)
          Collapse.erase(Collapse.begin());
        else
          break;
      }
      if(Collapse.empty())
        break;
      // cout<<x<<","<<y<<endl;
      if(AIdx[x] == 0)
        Total += Atom[x][3];
      AIdx[x] = -1;
      if(AIdx[y] == 0)
        Total += Atom[y][3];
      AIdx[y] = -1;
      Collapse.erase(Collapse.begin());
      if(Collapse.begin()->first == t){
        x = Collapse.begin()->second.first;
        y = Collapse.begin()->second.second;
      }else
        break;
    }while(!Collapse.empty());

    // cout<<"---------"<<endl;
    for(int i=0; i<N; i++){
      // cout<<AIdx[i]<<" ";
      if(AIdx[i] == -1)
        AIdx[i] = 1;
    }
    cout<<endl;
  }
}
int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d",&N );
    for(int i=0; i<N; i++){
      vector<int> temp(4);
      scanf("%d%d%d%d",&temp[0],&temp[1],&temp[2],&temp[3] );
      Atom.push_back(temp);
    }

    fill_n(AIdx,N,0);
    Total = 0;
    check();
    erase();
    printf("#%d %d\n",t+1,Total);
    Atom.clear();
  }
}
