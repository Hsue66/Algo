//#include<iostream>
#include<cstdio>
#include<vector>
#define Max 26

using namespace std;

vector <pair<int,int> > Tree(Max);

void preOrder(int root){
  printf("%c",root+'A');
  if(Tree[root].first+'A' != '.')
    preOrder(Tree[root].first);
  if(Tree[root].second+'A' != '.')
    preOrder(Tree[root].second);
}

void inOrder(int root){
  if(Tree[root].first+'A' != '.')
    inOrder(Tree[root].first);
  printf("%c",root+'A');
  if(Tree[root].second+'A' != '.')
    inOrder(Tree[root].second);
}

void postOrder(int root){
  if(Tree[root].first+'A' != '.')
    postOrder(Tree[root].first);
  if(Tree[root].second+'A' != '.')
    postOrder(Tree[root].second);
  printf("%c",root+'A');
}

int main(){
  int N;
  scanf("%d%*c",&N);
  while(N--){
    char root, left, right;
    scanf("%c%*c%c%*c%c%*c",&root,&left,&right);
    Tree[root-'A'] = make_pair(left-'A',right-'A');
  }

  preOrder(0);
  printf("\n");
  inOrder(0);
  printf("\n");
  postOrder(0);
  printf("\n");
}
