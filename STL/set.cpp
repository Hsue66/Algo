#include<iostream>
#include<set>

using namespace std;

int main(){
  set<int> S1;
  set<int,greater<int> > S2;
  S1.insert(3);
  S1.insert(0);
  S1.insert(5);
  S1.insert(2);
  S2.insert(3);
  S2.insert(0);
  S2.insert(5);
  S2.insert(2);

  for(auto it=S1.begin(); it!=S1.end(); ++it)
    cout<<(*it)<<" ";
    cout<<endl;
  for(auto it=S2.begin(); it!=S2.end(); ++it)
    cout<<(*it)<<" ";
    cout<<endl;

  if(S2.find(3) == S2.end())
    cout<<"Not"<<endl;
  else
    cout<<"IN"<<endl;

  if(S2.find(1) == S2.end())
    cout<<"Not"<<endl;
  else
    cout<<"IN"<<endl;
}
