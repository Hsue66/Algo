#include<cstdio>
//#include<iostream>
#include<cmath>
#include<stack>

using namespace std;

stack<char> n1;
stack<char> n2;
stack<char> result;

int toInt(stack<char> &n){
  int num=0;
  int i=0;
  while(!n.empty() && i<8){
    num += (n.top()-'0')*pow(10,i++);
    n.pop();
  }
  return num;
}

int main(){
  char val=0;
  int flag = -1;
  while(val != 10 && scanf("%c",&val)==1){
    if(val!=' '){
      if(flag > 0)
        n2.push(val);
      else
        n1.push(val);
    }
    else
      flag++;
  }
  n2.pop();

  int lowerN1 = toInt(n1);
  int lowerN2 = toInt(n2);

  int num = lowerN1+lowerN2;

  int divC = 0;
  while(divC < 8 && num != 0){
    divC++;
    result.push(num%10);
    num = num/10;
  }
  for(int i = divC; i<8; i++)
    result.push(0);

  int upperN1 = toInt(n1);
  int upperN2 = toInt(n2);

  num = upperN1+upperN2+num;


  while(num != 0){
    result.push(num%10);
    num = num/10;
  }


  flag =0;
  while(!result.empty()){
    if(result.top() != 0)
      flag =1;
    if(flag)
      printf("%d", result.top());
    result.pop();
  }
  if(flag == 0)
    printf("0");
  printf("\n");
}
