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
        if(i==j)
          continue;
        if(friends[i][j]=='Y')
          count[i]++;
        else{
          for(int k=0; k<friends.size(); k++){
              if(friends[k][i]=='Y' && friends[j][k]=='Y')
                count[i]++;
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
