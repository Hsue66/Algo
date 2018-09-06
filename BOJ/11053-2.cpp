#include <iostream>     // cout
#include <algorithm>    // lower_bound, upper_bound, sort
#include <vector>       // vector
#define LIMIT 1001

using namespace std;

vector <int> ordered;
vector <int>::iterator idx;
int M[LIMIT];

int main () {
  int len;
  scanf("%d",&len );
  for(int i=0; i<len; i++){
    int num;
    scanf("%d",&num);
    ordered.push_back(num);
    sort(ordered.begin(), ordered.end());
    M[i] = lower_bound(ordered.begin(), ordered.end(), num) - ordered.begin();
  }

  for(int i=0; i<len; i++)
    cout<<M[i]<<" ";
  cout<<endl;

  return 0;
}
