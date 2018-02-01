#include <iostream>
#include <vector>

using namespace std;
class InterestingDigits{
public:
  vector<int> digits(int base)
  {
    vector<int> result;
    for(int i=2; i<base; i++){
      if((base-1)%i == 0)
        result.push_back(i);
    }

    for(int i=0; i<result.size(); i++)
      cout<<result[i]<<" ";

    return result;
  }
};

int main()
{
  int base;
  cin>>base;
  InterestingDigits ID;
  ID.digits(base);
}
