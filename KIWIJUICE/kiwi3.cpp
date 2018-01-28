#include<iostream>
#include<vector>

using namespace std;

class KiwiJuiceEasy{
public:
  vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId){
    int len = fromId.size();
    for(int i=0; i<len; i++)
    {
      int from = bottles[fromId[i]];
      int to = bottles[toId[i]];
      int sum = from + to;

      bottles[toId[i]] = min(sum, capacities[toId[i]]);
      bottles[fromId[i]] = sum - bottles[toId[i]];
    }
    return bottles;
  }
};

int main()
{
  KiwiJuiceEasy kiwi;
  cout<< "hey"<<endl;
  vector<int> capacities;
  vector<int> bottles;
  vector<int> fromId;
  vector<int> toId;
  /*
  capacities = {20,20};
  bottles = {5,8};
  fromId = {0};
  toId = {1};

  capacities = {10,10};
  bottles = {5,8};
  fromId = {0};
  toId = {1};

  capacities = {30,20,10};
  bottles = {10,5,5};
  fromId = {0,1,2};
  toId = {1,2,0};

  capacities = {14,35,86,58,25,62};
  bottles = {6,34,27,38,9,60};
  fromId = {1,2,4,5,3,3,1,0};
  toId = {0,1,2,4,2,5,3,1};
*/

  capacities = {700000,800000,900000,1000000};
  bottles = {478478,478478,478478,478478};
  fromId = {2,3,2,0,1};
  toId = {0,1,1,3,2};

  vector<int> result  = kiwi.thePouring(capacities, bottles, fromId, toId);
  for (int i = 0; i < result.size(); ++i)
     cout << result[i] << " ";
}
