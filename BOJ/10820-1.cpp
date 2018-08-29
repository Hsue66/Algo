#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main(){
  string str;
  int Cap,Low,Num,Space;

  while(!getline(cin,str).eof()){
    Cap = Low = Num = Space = 0;
    int len = str.length();

    for(int i=0; i<len; i++){
      if('a'<=str[i] && str[i] <='z')
        Low++;
      else if('A'<=str[i] && str[i] <='Z')
        Cap++;
      else if(str[i] == ' ')
        Space++;
      else
        Num++;
    }
    printf("%d %d %d %d\n",Low,Cap,Num,Space );
  }
}

/*
  while(scanf("%c",&val) != EOF){
    if(val == 10){
      printf("%d %d %d %d\n",Low,Cap,Num,Space );
      Cap = Low = Num = Space = 0;
    }else{
      if('a'<val && val <'z')
        Low++;
      else if('A'<val && val <'Z')
        Cap++;
      else if(val == ' ')
        Space++;
      else
        Num++;
    }
  }
  */
