#include<iostream>
#include<map>

using namespace std;

int main(){
  map<int,int> M1;
  map<int,int, greater<int> > M2;
  M1.insert(make_pair(3,0));
  M2[3] = 0;
  M1.insert(make_pair(5,1));
  M2[5] = 1;
  M1.insert(make_pair(1,2));
  M2[1] = 2;
  M1[6] = 3;
  M2[6] = 3;

  for(auto it=M1.begin(); it!=M1.end(); ++it)
    cout<<it->first<<" ";
  cout<<endl;

  for(auto it=M2.begin(); it!=M2.end(); ++it)
    cout<<(*it).first<<" ";
  cout<<endl;

  if(M1.find(3) == M1.end())
    cout<<"Not"<<endl;
  else
    cout<<"IN"<<endl;
}
