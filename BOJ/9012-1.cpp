#include<cstdio>
//#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int main(){
  int testcase;
  scanf("%d",&testcase);

  while(testcase--){
    stack <char> st;
    //string arr;
    char arr[51];
    int flag = 0;

    //cin >> arr;
    //int len = arr.length();
    scanf("%s",arr);
    int len = strlen(arr);

    for(int i=0; i<len; i++){
      if(arr[i] == '(')
        st.push('(');
      else if(arr[i] == ')' && st.size() != 0)
        st.pop();
      else{
        flag = 1;
        break;
      }
    }

    if(!st.empty())
      flag = 1;

    if(flag)
      printf("NO\n");
    else
      printf("YES\n");
  }
}
