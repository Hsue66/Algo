#include<cstdio>
//#include<iostream>
#include<stack>
#include<cstring>
#define MAX 100001

using namespace std;

int main(){
  char arr[MAX];
  scanf("%s",arr);

  stack <char> st;
  int flag = 1;
  int cnt = 0;
  int len = strlen(arr);

  for(int i=0; i<len; i++){
    if(arr[i]== '('){
      st.push('(');
      flag = 1;
    }
    else if(arr[i]== ')' && flag == 1){
      st.pop();
      cnt += st.size();
      flag = 0;
    }
    else if(arr[i]== ')' && flag == 0){
      st.pop();
      cnt += 1;
      flag = 0;
    }
  }
  printf("%d\n",cnt);
}
