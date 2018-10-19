//#include<iostream>
#include<cstdio>
#define LIMIT 11

using namespace std;

char Number[LIMIT];
int Active[LIMIT][7] = {{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},
                        {1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
char MAP[LIMIT*2+3][(LIMIT+2)*LIMIT];
int S;
//int dir[2][2] = {{0,1},{1,0}};

void fillMap(int sw, int loc){
  if(loc%3 == 0){
    int idx = loc/3;
    for(int i=0; i<S; i++)
      MAP[idx*S+idx][(sw+1)+1*i]='-';
  }else{
    int x = 1;
    int y = sw;
    if(loc%3 == 2)
      y = sw+S+1;
    if(loc/3 == 1)
      x = S+2;

    for(int i=0; i<S; i++)
      MAP[x+1*i][y]='|';
  }
}

int main(){
  scanf("%d%*c",&S);
  int len;
  for(len=0; len<LIMIT; len++){
    char t;
    scanf("%1c",&t);
    if(t == '\n')
      break;
    Number[len]= t;
  }

  for(int j=0; j<2*S+3; j++){
    for(int i=0; i<(len-1)*(S+3)+S+2; i++)
      MAP[j][i] = ' ';
  }

  for(int i=0; i<len; i++){
    for(int j=0; j<7; j++){
      if(Active[Number[i]-'0'][j] == 1)
        fillMap((S+2)*i+i, j);
    }
  }

  for(int j=0; j<2*S+3; j++){
    for(int i=0; i<(len-1)*(S+3)+S+2; i++)
      printf("%c",MAP[j][i]);
    printf("\n");
  }
}
