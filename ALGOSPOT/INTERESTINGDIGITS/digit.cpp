#include <iostream>
#include <vector>

using namespace std;
class InterestingDigits{
public:
  vector<int> digits(int base)
  {
    vector<int> result;
    int no = 0;
    for(int multi=2; multi<base; multi++){
      for(int x=0; x<base; x++){
        for(int y=0; y<base; y++){
          for(int z=0; z<base; z++){
            if( (x*base*base+y*base+z)% multi == 0 && (x+y+z)%multi != 0)
            {
              //cout<<" "<<multi<<endl;
              no =1;
              break;
            }
          }
          if(no == 1)
            break;
        }
        if(no == 1)
          break;
      }
      if(no == 1)
        no =0;
      else
        result.push_back(multi);
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
