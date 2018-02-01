#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class ThePalindrome{
public:
  int find(string s){
      int min = s.size()*2-1;

      for(int i=s.size()-1; i>=s.size()/2; i--){
        string right = s.substr(i,s.size());
        reverse(right.begin(), right.end());

        int dif = right.size();
        string left;
        for(int idx = i-dif; idx<i; idx++)
          left += s[idx];


        if(left.compare(right)==0){
          int fulllen = 2*s.size() - right.size() - left.size();
          //cout<<fulllen<<" YES"<<endl;
          if(min>fulllen)
            min = fulllen;
        }
      }

      for(int i=s.size()-1; i>=s.size()/2; i--){
        int len = s.size()-i-1;

        string left;
        for(int idx = i-len; idx<i; idx++)
          left += s[idx];

        //cout<< left<<" ";

        string right = s.substr(i+1,s.size());
        reverse(right.begin(), right.end());
        //cout<<right<<endl;

        if(left.compare(right)==0){
          int fulllen = 2*i+1;
          //cout<<2*i+1<<" YES"<<endl;
          if(min>fulllen)
            min = fulllen;
        }
      }

    return min;
  }
};

int main()
{
    string s;
    cin>> s;
    ThePalindrome pal;
    cout<< pal.find(s);
}
