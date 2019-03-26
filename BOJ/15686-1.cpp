#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int N,M;
vector<pair<int,int> > Chicken;
vector<pair<int,int> > House;
int Clen,Hlen;
int dist[100][13];
int mDist[100];
int Min;

void findAllDist(){
  for(int i=0; i<Hlen; i++){
    int Hx = House[i].first;
    int Hy = House[i].second;
    for(int j=0; j<Clen; j++){
      int Cx = Chicken[j].first;
      int Cy = Chicken[j].second;
      dist[i][j] = abs(Hx-Cx)+abs(Hy-Cy);
    }
  }
}

void findCase(int idx, int cnt){
  if(cnt == M){
    int acc = 0;
    for(int j=0; j<House.size(); j++)
      acc += mDist[j];
    if(Min > acc)
      Min = acc;
  }else{
    for(int i=idx+1; i<Clen; i++){
      int temp[100];
      copy(mDist,mDist+Hlen,temp);

      for(int j=0; j<Hlen; j++)
        mDist[j] = min(dist[j][i],mDist[j]);
      findCase(i,cnt+1);
      copy(temp, temp+Hlen, mDist);
    }
  }
}

int main(){
  scanf("%d%d",&N,&M );
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      int t;
      scanf("%d",&t );
      if(t == 2)
        Chicken.push_back(make_pair(i,j));
      else if(t == 1)
        House.push_back(make_pair(i,j));
    }
  }
  Min = 987654321;

  Clen = Chicken.size();
  Hlen = House.size();

  findAllDist();

  for(int i=0; i<=Clen-M; i++){
    for(int j=0; j<Hlen; j++)
      mDist[j] = dist[j][i];

    findCase(i,1);
  }
  printf("%d\n",Min);
}
