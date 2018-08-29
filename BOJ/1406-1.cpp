#include <cstdio>
//#include <iostream>
#include <stack>

using namespace std;

stack<char> leftS;
stack<char> rightS;

int main(){
  char a;
  do{
    scanf("%c",&a);
    leftS.push(a);
  }while(a != '\n');
  leftS.pop();

  int loop;
  scanf("%d%*c",&loop);

  while(loop--){
    char command;
    scanf("%c%*c",&command);

    if(command == 'P'){
      char temp;
      scanf("%c%*c",&temp );
      leftS.push(temp);
    }
    else if(command == 'L'){
      if(!leftS.empty()){
        rightS.push(leftS.top());
        leftS.pop();
      }
    }
    else if(command == 'D'){
      if(!rightS.empty()){
        leftS.push(rightS.top());
        rightS.pop();
      }
    }
    else if(command == 'B'){
      if(!leftS.empty())
        leftS.pop();
    }
  }

  while(!leftS.empty()){
    rightS.push(leftS.top());
    leftS.pop();
  }

  while(!rightS.empty()){
    printf("%c",rightS.top());
    rightS.pop();
  }
  printf("\n");
}
