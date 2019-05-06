#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int R,C,M;
int NowC = 0;
int NowR,NowZ;
int Sum;

struct shark{
  int r,c,s,d,z;
};
vector<shark> Sharks;
int Dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void moveSharks(){
  vector<shark> NewSharks;
  int lenS = Sharks.size();
  for(int i=0; i<lenS; i++){
    if(Sharks[i].z == NowZ)
      continue;
    int d = Sharks[i].d;
    int tr = Sharks[i].r + (Sharks[i].s*Dir[d][0]);
    int tc = Sharks[i].c + (Sharks[i].s*Dir[d][1]);
    cout<<d<<" "<<Sharks[i].s<<endl;
    cout<<Sharks[i].r<<" "<<Sharks[i].c<<"->"<<tr<<" "<<tc<<endl;
  }
}

void fishing(){
  while(NowC++ < C){
    //ㄱㅏ까운 상어 빠이
    if(NowR != R){
      Sum += NowZ;

    }
    moveSharks();
    NowR = R;
    NowZ = -1;
    char a;
    cin>>a;
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
