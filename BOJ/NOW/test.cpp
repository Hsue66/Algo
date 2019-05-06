#include<iostream>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

int main(){
  for(int i=0; i<10; i++){
    if(i==3)
      continue;
    cout<<i<<endl;
  }
  map<pair<int,int>, vector<int> > Temp;
  vector<int> t;
  t.push_back(3);
  t.push_back(2);
  t.push_back(1);
  Temp.insert(make_pair(make_pair(0,1),t));

  for(auto it=Temp.begin(); it!=Temp.end(); ++it){
    cout<<(*it).second[0]<<(*it).first.second<<endl;
  }
}
