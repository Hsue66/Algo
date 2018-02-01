#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class FriendScore{
public:
  int highestScore(vector<string> friends)
  {
    int max=0;
    vector<int> count;
    for(int i=0; i<friends.size(); i++)
      count.push_back(0);

    for(int i=0; i<friends.size(); i++){
      for(int j=0; j<friends.size(); j++){
        if(friends[i][j]=='Y'){
          count[i]++;
          for(int k=0; k<friends.size(); k++){
            if(k!=j && (friends[k][i]=='Y' && friends[k][j]!='Y'))
              count[k]++;
          }
        }
      }
    }

    max = *max_element(count.begin(),count.end());

    return max;
  }
};

int main()
{
  vector<string> friends;
  friends = {"NYY","YNY","YYN"};
  //friends = {"NYNNN","YNYNN","NYNYN","NNYNY","NNNYN"};
  FriendScore fr;
  cout<<fr.highestScore(friends);
}
