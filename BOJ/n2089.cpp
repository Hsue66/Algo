#include<cstdio>
#include<stack>
//#include<iostream>
#define DIV -2

using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	stack<int> S;

	do{
		int left = num % DIV;
		num = num/DIV;
		
		if(left<0){
			left = 1;
			num++;
		}
		S.push(left);
	}while(num != 0);

	while(!S.empty()){
		printf("%d",S.top());
		S.pop();
	}
	printf("\n");
}
