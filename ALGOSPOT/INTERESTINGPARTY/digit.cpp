#include <iostream>
#include <vector>

using namespace std;
class InterestingDigits{
public:
  vector<int> digits(int base)
  {
    int multi = 2;
    while(multi < 10){
      for(i=2; i<base; i++)
      {
        cout<<base*i<<" ";
      }
    }
    cout<<endl;
  }
};

int main()
{
  int base;
  cin>>b>>endl;
  InterestingDigits ID;
  ID.digits(b);
}
