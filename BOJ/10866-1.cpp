#include<cstdio>
#include<cstring>
//#include<iostream>
#define MAX 20002

using namespace std;

int Arr[MAX];
int frontIdx = MAX/2;
int backIdx = MAX/2;

int main(){
  int loop;
  scanf("%d",&loop );
  while(loop--){
    char command[11];
    scanf("%s",command );

    if(strcmp(command,"push_front")==0)
      scanf("%d", &Arr[--frontIdx] );

    else if(strcmp(command,"push_back")==0)
      scanf("%d", &Arr[backIdx++] );

    else if(strcmp(command,"pop_front")==0){
      if(backIdx-frontIdx >0)
        printf("%d\n",Arr[frontIdx++] );
      else
        printf("-1\n");
    }
    else if(strcmp(command,"pop_back")==0){
      if(backIdx-frontIdx >0)
        printf("%d\n",Arr[--backIdx] );
      else
        printf("-1\n");
    }
    else if(strcmp(command,"front")==0){
      if(backIdx-frontIdx >0)
        printf("%d\n",Arr[frontIdx] );
      else
        printf("-1\n");
    }
    else if(strcmp(command,"back")==0){
      if(backIdx-frontIdx >0)
        printf("%d\n",Arr[backIdx-1] );
      else
        printf("-1\n");
    }
    else if(strcmp(command,"size")==0)
      printf("%d\n",backIdx-frontIdx);

    else if(strcmp(command,"empty")==0){
      if(backIdx-frontIdx >0)
        printf("0\n");
      else
        printf("1\n");
    }
  }
}
