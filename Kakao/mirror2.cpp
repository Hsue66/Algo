#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#define LIMIT 17
using namespace std;

int MAP[LIMIT][LIMIT] = {0};

void fillMap(int n, vector<int> arr){
    for(int i=0; i<n; i++){
      int now = arr[i];
      int cnt = n;

      do{
        MAP[i][--cnt] += now%2;
        now = now/2;
      }while(now);
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    cout<<bitset<2>(arr1[0]|arr2[0])<<endl;
    return answer;
}

int main(){
  int n = 6;
  static const int arr[] = {46,33,33,22,31,50};
  vector<int> vec1 (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  static const int arr2[] = {27,56,19,14,14,10};
  vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

  solution(n,vec1,vec2);
}
