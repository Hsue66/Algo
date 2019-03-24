#include<iostream>
#include<vector>

using namespace std;

class InterestingParty{
public:
  int bestInvitation(vector<string> first, vector<string> second){
    int max = 0;
    int len = first.size();
    vector<string> Done;

    for(int i=0; i<len*2; i++)
    {
      string Now;
      if(i%2 == 0)
        Now = first[i/2];
      else
        Now = second[i/2];

      //cout<<Now <<endl;
      int mark = 0;
      for(int j=0; j<Done.size(); j++){
        if(Done[j]==Now)
          mark = 1;
      }

      int cnt=1;
      if(mark != 1){
        Done.push_back(Now);
        for(int j=0; j<len; j++)
        {
          if(i/2 != j)
          {
            if(Now == first[j] || Now == second[j])
              cnt++;
          }
        }
      }
      if(max<cnt)
        max = cnt;
    }
    return max;
  }
};

int main()
{
  vector<string> first;
  vector<string> second;


  first = {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r", "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"};
  second = {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"};

  InterestingParty party;
  cout<<party.bestInvitation(first, second);
}
