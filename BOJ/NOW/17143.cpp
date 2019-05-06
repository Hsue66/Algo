#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;

int R,C,M;
int NowC = 0;
int NowR,NowZ;
int Sum;

struct shark{
  int r,c,s,d,z;
};
vector<shark> Sharks;
int Dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

void moveSharks(){
  map<pair<int,int>,vector<int> > NewSharks;
  int lenS = Sharks.size();
  for(int i=0; i<lenS; i++){
    if(Sharks[i].z == NowZ)
      continue;

    int d = Sharks[i].d;
    int size = R-1;
    int loc = Sharks[i].r;
    if(d%2 == 1){
      size = C-1;
      loc = Sharks[i].c;
    }
    int left = Sharks[i].s % (size*2);
    while(left != 0){
      int diff = loc;
      if(d/2 == 1)
        diff = size-loc;
      if(left > diff){
        loc = 0;
        if(d/2 == 1)
          loc = size;
        left -= diff;
        d = (d+2)%4;
      }else{
        if(d%2==0)
          Sharks[i].r = loc + left * Dir[d][0];
        else
          Sharks[i].c = loc + left * Dir[d][1];
        left = 0;
      }
    }
    vector<int> temp(3);
    temp[0] = Sharks[i].s;
    temp[1] = d;
    temp[2] = Sharks[i].z;
    pair<int,int> pos = make_pair(Sharks[i].r,Sharks[i].c);

    if(NewSharks.find(pos) != NewSharks.end()){
      if(NewSharks[pos][2] < temp[2])
        NewSharks[pos] = temp;
    }else
      NewSharks.insert(make_pair(pos,temp));
  }

  vector<shark> nsharks;
  for(auto it=NewSharks.begin(); it!=NewSharks.end(); ++it){
    shark t;
    t.r = (*it).first.first;
    t.c = (*it).first.second;
    t.s = (*it).second[0];
    t.d = (*it).second[1];
    t.z = (*it).second[2];

    if(NowC == t.c){
      if(NowR > t.r){
        NowR = t.r;
        NowZ = t.z;
      }
    }
    nsharks.push_back(t);
  }

  swap(Sharks,nsharks);
}

void fishing(){
  while(NowC++ < C){
    //ㄱㅏ까운 상어 빠이
    // cout<<NowZ<<endl;
    if(NowR != R)
      Sum += NowZ;
    NowR = R;
    moveSharks();
    // cout<<"left: "<<Sharks.size()<<endl;
    // char a;
    // cin>>a;
  }
}

int main(){
  scanf("%d%d%d",&R,&C,&M );
  NowR = R;
  NowZ = -1;
  while(M--){
    shark t;
    scanf("%d%d%d%d%d",&t.r,&t.c,&t.s,&t.d,&t.z );
    t.r--;
    t.c--;
    t.d--;
    if(t.d == 1)
      t.d = 2;
    else if(t.d == 2)
      t.d = 3;
    else if(t.d == 3)
      t.d = 1;
    Sharks.push_back(t);
    if(NowC == t.c){
      if(NowR > t.r){
        NowR = t.r;
        NowZ = t.z;
      }
    }
  }
  Sum = 0;
  fishing();
  printf("%d\n",Sum );
}
