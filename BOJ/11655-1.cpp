#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
  char val=0;
  while(val != 10 && scanf("%c",&val)==1){
    int res;
    if('a'<=val && val <='z'){
      res = val +13;
      if(res > 'z')
        res = res%'z'+'a'-1;
    }
    else if('A'<=val && val <='Z'){
      res = val +13;
      if(res > 'Z')
        res = res%'Z'+'A'-1;
    }
    else
      res = val;
    printf("%c",res );
  }
}
