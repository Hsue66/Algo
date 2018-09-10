#include<cstdio>
//#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int> > cord;

bool compare(pair<int,int> a, pair<int,int> b){
  if(a.second == b.second)
    return a.first < b.first;
  else
    return a.second < b.second;
}

int main(){
  int N;
  scanf("%d",&N );
  for(int i=0; i<N; i++){
    int x,y;
    scanf("%d%d",&x,&y );
    cord.push_back(make_pair(x,y));
  }

  sort(cord.begin(),cord.end(),compare);

  for(int i=0; i<N; i++)
    printf("%d %d\n",cord[i].first,cord[i].second);
}
