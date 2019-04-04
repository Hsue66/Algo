#include<iostream>
#include<map>

using namespace std;

map<int,int> Pos;

int main(){
  Pos.insert(make_pair(0,0));
  Pos.insert(make_pair(1,0));

  for(auto it=Pos.begin(); it!=Pos.end(); ++it)
    cout<<it->first<<" "<<it->second<<endl;
  Pos.insert(make_pair(1,1));
  Pos.insert(make_pair(2,1));
  for(auto it=Pos.begin(); it!=Pos.end(); ++it)
    cout<<it->first<<" "<<it->second<<endl;

  if(Pos.find(2) == Pos.end()){
    cout<<"NOT"<<endl;
  }else{
    cout<<"IN"<<endl;
  }
}
