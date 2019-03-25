#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<pair<int,int>,vector<int> > > LiveT;
int A[10][10];
int Earth[10][10];
int News[10][10] = {0};
queue<pair<int,int> > NewT;
int Dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
long long Cnt;

int N,M,K;

void sortTree(){
  Cnt = 0;
  int lenPos = LiveT.size();
  for(int i=0; i<lenPos; i++){
    long long s = LiveT[i].second.size();
    Cnt += s;
    // for(int j=0; j<s; j++)
    //   cout<<LiveT[i].second.at(j)<<" ";
    //   cout<<endl;
    sort(LiveT[i].second.begin(), LiveT[i].second.end());
    // for(int j=0; j<s; j++)
    //   cout<<LiveT[i].second.at(j)<<" ";
    //   cout<<endl;
    // cout<<"---------------"<<endl;
  }
  //cout<<"count "<<Cnt<<endl;
}

void addNew(){
  while(!NewT.empty()){
    int flag = 0;
    pair<int,int> nPos = NewT.front();
    int x = nPos.first;
    int y = nPos.second;
    NewT.pop();

    int lenPos = LiveT.size();
    for(int j =0; j<lenPos; j++){
      if(nPos == LiveT[j].first){
        flag = 1;

        for(int r=0; r<News[x][y]; r++)
          LiveT[j].second.push_back(1);
      }
    }
    if(flag == 0){
      vector<int> ones;
      for(int r=0; r<News[x][y]; r++)
        ones.push_back(1);
      LiveT.push_back(make_pair(make_pair(x,y),ones));
    }
  }
  sortTree();
}

void passYear(){
  //cout<<K<<"-----------------------"<<endl;
  int lenPos = LiveT.size();
  for(int i=0; i<lenPos; i++){
    pair<int,int> pos = LiveT[i].first;
    int x = pos.first;
    int y = pos.second;
    int lenTrees = LiveT[i].second.size();
    //cout<<lenTrees<<endl;
    vector<int> sTrees;
    int dead = 0;
    for(int t=0; t<lenTrees; t++){
      if(Earth[x][y] - LiveT[i].second.at(t) >= 0){   // 양분먹기 가능
        Earth[x][y] = Earth[x][y] - LiveT[i].second.at(t);
        int age = LiveT[i].second.at(t)+1;
        sTrees.push_back(age);
        if(age %5 == 0){ // 나무 추가
          for(int d =0; d<8; d++){
            int tx = Dir[d][0] + x;
            int ty = Dir[d][1] + y;
            if(0<= tx && tx < N && 0<= ty && ty < N){
              if(News[tx][ty] == 0)
                NewT.push(make_pair(tx,ty));
              News[tx][ty]++;
            }
          }
        }
      }
      else //죽는 애들
        dead += (LiveT[i].second.at(t)/2);
    }
    LiveT[i] = make_pair(pos,sTrees);
    Earth[x][y] += dead;
  }

  addNew();

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      Earth[i][j] += A[i][j];
      News[i][j] = 0;
      //cout<<Earth[i][j]<<" ";
    }
    //cout<<endl;
  }

  // int a;
  // cin>>a;
}

int main(){
  scanf("%d%d%d",&N,&M,&K);
  for(int i=0; i<N; i++)
    fill_n(Earth[i],N,5);
  // 비료
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      scanf("%d",&A[i][j]);
  }
  // 나무
  for(int i=0; i<M; i++){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    vector<int> t;
    t.push_back(z);
    LiveT.push_back(make_pair(make_pair(x-1,y-1),t));
  }
  while(K--)
    passYear();
  printf("%lld\n",Cnt );
}
