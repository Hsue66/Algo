#include<stdio.h>

#define MAX 101
int main(){
  for(int t=0; t<10; t++){
    int n, s = -1;
    int str[MAX];
    scanf("%d",&n );
    for(int i=0; i<n; i++){
      scanf("%1d",&str[++s]);
      if(0 < s){
        if(str[s-1] == str[s])
          s = s-2;
      }
    }
    printf("#%d ",t+1);
    for(int i=0; i<=s; i++)
      printf("%d",str[i]);
    printf("\n");
  }
}
