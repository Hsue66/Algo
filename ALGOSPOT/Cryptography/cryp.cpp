#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

class Cryptograph{
public:
  long long encrypt(vector<int> numbers){
    map <int, int> arr;

    for(int i=0; i<numbers.size(); i++){
      arr[numbers[i]]=0;
    }

    for(int i=0; i<numbers.size(); i++){
      arr[numbers[i]]++;
    }

    map<int,int>::iterator it;
    map<int,int>::iterator it2;
/*    for(it=arr.begin(); it!=arr.end(); it++){
      cout<<it->first<<" : "<<it->second<<endl;
    }
*/
    long long max = 0;
    long long mul=1;

    for(it2=arr.begin(); it2!=arr.end(); it2++){
      for(it=arr.begin(); it!=arr.end(); it++){
        if(it->first == it2->first){
            mul *= (it->first+1)*pow(it->first, it->second-1);
        }
        else{
            mul *= pow(it->first, it->second);
        }
      }
      //cout<<mul<<endl;
      if(max < mul)
        max = mul;
      mul=1;
    }

    return max;
  }

};

int main()
{
  Cryptograph cryp;
  vector<int> nums = {1,1,1,1};
  cout<< cryp.encrypt(nums);
}
