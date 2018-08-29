#include<cstdio>
#include <cstring>
//#include<iostream>
#define MAX 100001

using namespace std;

int queue[MAX];
int firstIdx = 0;
int lastIdx = 0;

int main(){
  int loop;
  scanf("%d",&loop );
  while(loop--){
    char command[6];
    scanf("%s",command);

    if(strcmp(command,"push") == 0)
      scanf("%d",&queue[lastIdx++] );

    else if(strcmp(command,"pop") == 0){
      if(lastIdx-firstIdx > 0)
        printf("%d\n",queue[firstIdx++]);
      else
        printf("-1\n");
    }
    else if(strcmp(command,"front") == 0){
      if(lastIdx-firstIdx > 0)
        printf("%d\n",queue[firstIdx]);
      else
          printf("-1\n");
    }
    else if(strcmp(command,"back") == 0){
      if(lastIdx-firstIdx > 0)
        printf("%d\n",queue[lastIdx-1]);
      else
        printf("-1\n");
    }
    else if(strcmp(command,"size") == 0)
      printf("%d\n",lastIdx-firstIdx);

    else if(strcmp(command,"empty") == 0){
      if(lastIdx-firstIdx > 0)
        printf("0\n" );
      else
        printf("1\n" );
    }
  }
}
