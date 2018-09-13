#include <string>
#include <iostream>

#include <cstdio>
#define PRIME 10001
#define MULTI 65536

using namespace std;

int Hash[PRIME] = {0};
int total = 0;
int same = 0;
int second = 0;

int solution(string str1, string str2) {
    int answer = 0;

    for(int i=0; i<str1.length()-1; i++){
      if(isalpha(str1[i]) && isalpha(str1[i+1])){
        int idx = toupper(str1[i])*100 + toupper(str1[i+1]);
        Hash[idx]++;
        total++;
      }
    }
    for(int i=0; i<str2.length()-1; i++){
      if(isalpha(str2[i]) && isalpha(str2[i+1])){
        int idx = toupper(str2[i])*100 + toupper(str2[i+1]);
        second++;
        if(Hash[idx]>0)
          same++;
        Hash[idx]--;
      }
    }

    if(total+second-same)
      answer = (MULTI*same)/(total+second-same);
    else
      answer = 1*MULTI;

    return answer;
}

int main(){
  string str1 = "ABAABAA";
  string str2 = "aab";
  cout<<solution(str1, str2)<<endl;
}
