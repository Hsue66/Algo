#include<cstdio>
#include<stack>
//#include<iostream>

using namespace std;

int num,base;
stack<char> S;

int main(){
	scanf("%d%d",&num,&base);

	do{
		int left = num % base;
		char val = '0'+left;
		if(left >= 10)
			val = left-10+'A';
		S.push(val);
		num = num / base;
	}while(num != 0);


	while(!S.empty()){
		printf("%c",S.top());
		S.pop();
	}
	printf("\n");
}
