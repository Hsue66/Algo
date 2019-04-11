#include<iostream>
#include<map>

using namespace std;

int main(){
  multimap<int,int> M1;
  multimap<int,int, greater<int> > M2;
  M1.insert(make_pair(3,0));
  M2.insert(make_pair(3,0));
  M1.insert(make_pair(5,1));
  M2.insert(make_pair(5,1));
  M1.insert(make_pair(1,2));
  M2.insert(make_pair(1,2));
  M1.insert(make_pair(5,0));
  M2.insert(make_pair(5,0));

  for(auto it=M1.begin(); it!=M1.end(); ++it)
    cout<<it->first<<" "<<it->second<<endl;
  cout<<endl;

  for(auto it=M2.begin(); it!=M2.end(); ++it)
    cout<<(*it).first<<" "<<(*it).second<<endl;
  cout<<endl;

  if(M2.find(5) == M2.end())
    cout<<"Not"<<endl;
  else
    cout<<"IN"<<endl;
}
