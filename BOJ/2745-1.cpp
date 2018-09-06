#include<cstdio>
#include<iostream>
#include<string>

using namespace std;
int main(){
  string str;
  cin >> str;
  int B;
  scanf("%d",&B );
  int len = str.length();
  int sum = 0;
  for(int i=0; i<len; i++){
    int val = str[i];
    if('A' <= val && val <= 'Z')
      val = val -'A'+10;
    else
      val = val -'0';

    sum = sum*B +val ;
  }
  printf("%d\n",sum );
}
