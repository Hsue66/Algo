#include<iostream>
#include<cstdio>
#include<string>
#define MAX 10001

using namespace std;

int Stack[MAX];
int idx = -1;

int main(){
  int num;
  scanf("%d",&num);

  for(int i=0; i<num; i++){
    string command;
    cin>>command;

    if(command == "push")
        scanf("%d",&Stack[++idx]);

    else if(command == "size")
      printf("%d\n",idx+1);

    else if(command == "empty"){
      if(idx <0) printf("1\n");
      else  printf("0\n");
    }

    else if(command == "top"){
      if(idx >= 0) printf("%d\n",Stack[idx]);
      else  printf("-1\n");
    }

    else{
      if(idx >= 0) printf("%d\n",Stack[idx--]);
      else  printf("-1\n");
    }
  }
}
