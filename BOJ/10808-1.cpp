#include<cstdio>
#include<cstring>
//#include<iostream>

using namespace std;

char str[101];
int alphabet[26]={0};

int main(){
    scanf("%s",str );
    int len = strlen(str);

    for(int i=0; i<len; i++)
      alphabet[str[i]-'a']++;

    for(int i=0; i<26; i++)
      printf("%d ",alphabet[i]);
    printf("\n");
}
