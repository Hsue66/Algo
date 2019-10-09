#include<stdio.h>

#include<iostream>
using namespace std;

#define MAX 10001
int ancestor,size,V,E;
int Tree[MAX][4];

void show(){
  for(int i=0; i<=V; i++){
    for(int j=0; j<4; j++)
      cout<< Tree[i][j] <<" ";
      cout<<endl;
  }
}

void init(){
  for(int i=0; i<MAX; i++){
    for(int j=0; j<4; j++)
    Tree[i][j] = 0;
  }
}

int findAncestor(int s1, int s2){
  int visit[MAX] = {0};
  while(Tree[s1][2] != 0){  //하나의 조상 마킹
    visit[s1] = 1;
    s1 = Tree[s1][2];
  }
  while(Tree[s2][2] != 0 && visit[s2] != 1){
    visit[s2] = 1;
    s2 = Tree[s2][2];
  }
  return s2;
}

int findSize(int root){
  if(root == 0)
    return 0;
  if(Tree[root][0] == 0 && Tree[root][1] == 0){
    Tree[root][3] = 1;
    return Tree[root][3];
  }
  if (Tree[root][3] != 0)
    return Tree[root][3];
  else
    Tree[root][3] = findSize(Tree[root][0]) + findSize(Tree[root][1]) +1;
  return Tree[root][3];
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int tc=0; tc<testcase; tc++){
    int s1,s2,s,t;
    init();
    scanf("%d%d%d%d",&V,&E,&s1,&s2 );
    for(int i=0; i<E; i++){
      scanf("%d%d",&s,&t );
      if(Tree[s][0]==0)
        Tree[s][0] = t;
      else
        Tree[s][1] = t;
      Tree[t][2] = s;
    }
    ancestor = findAncestor(s1,s2);
    size = findSize(ancestor);

    printf("#%d %d %d\n",tc+1,ancestor,size );
  }
}
