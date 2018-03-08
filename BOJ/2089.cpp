#include<cstdio>
#include<stack>
//#include<iostream>

using namespace std;


int main(){
	int input;
	scanf("%d",&input);
	stack<int> st;
	int base = -2;

	do{
		int left = input%base;
		if(input < 0){
			input = input/base;
			if(left < 0){
				st.push(1);
				input = input +1;
			}
			else
				st.push(left);
		}
		else{
			input = input/base;
			st.push(left);
		}
	}while(input!=0);

	while(!st.empty()){
		printf("%d",st.top());
		st.pop();
	}
	printf("\n");
}
