//#include<iostream>
#include<cstdio>
#include<stack>

#define MAX 102

using namespace std;

int preOrder[MAX];
int inOrder[MAX];
stack<int> S;

void findPost(int pL, int pR, int iL, int iR){
  int root = preOrder[pL];
  S.push(root);
  int splitI = -1;
  for(int i=iL; i<=iR; i++){
    if(root == inOrder[i])
      splitI = i-iL+1;
  }

  if((pR-splitI-pL) >= 0 && (iR-splitI-iL) >= 0)
    findPost(pL+splitI, pR, iL+splitI, iR);
  if((pL+splitI-1-pL-1) >= 0 && (iL+splitI-2-iL) >= 0)
    findPost(pL+1, pL+splitI-1, iL, iL+splitI-2);
}

int main(){
  int testcase;
  scanf("%d",&testcase);
  while(testcase--){
    int N;
    scanf("%d",&N );
    for(int i=1; i<=N; i++)
      scanf("%d",&preOrder[i] );
    for(int i=1; i<=N; i++)
      scanf("%d",&inOrder[i] );

    findPost(1,N,1,N);

    while(!S.empty()){
      printf("%d ",S.top() );
      S.pop();
    }
    printf("\n");
  }
}
