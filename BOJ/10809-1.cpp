#include<cstdio>
#include<iostream>
using namespace std;

int alphabet[26];

int main(){
  char val;
  fill_n(alphabet,26,-1);
  int idx = 0;
  while(val != 10 && scanf("%c",&val) ==1){
    if(val != 10 && alphabet[val-'a'] == -1)
      alphabet[val-'a'] = idx;
    idx++;
  }

  for(int i=0; i<26; i++)
    printf("%d ",alphabet[i]);
  printf("\n");
}
