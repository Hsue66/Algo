#include<cstdio>
#include<vector>
//#include<iostream>

using namespace std;

vector<pair<int,int> > T(27);

void preOrder(int root){
	int left = T[root].first;
	int right = T[root].second;
	printf("%c",root+'A');
	if(left > 0)
		preOrder(left);
	if(right > 0)
		preOrder(right);
}

void inOrder(int root){
	int left = T[root].first;
	int right = T[root].second;
	if(left > 0)
		inOrder(left);
	printf("%c",root+'A');
	if(right > 0)
		inOrder(right);
}

void postOrder(int root){
	int left = T[root].first;
	int right = T[root].second;
	if(left > 0)
		postOrder(left);
	if(right > 0)
		postOrder(right);
	printf("%c",root+'A');
}

int main(){
	int N;
	scanf("%d%*c",&N);
	for(int i=0; i<N; i++){
		char root,left,right;
		scanf("%c%*c%c%*c%c%*c",&root,&left,&right);
		T[root-'A'] = make_pair(left-'A',right-'A');
	}	
	
	preOrder(0);
	printf("\n");
	
	inOrder(0);
	printf("\n");

	postOrder(0);
	printf("\n");
}
