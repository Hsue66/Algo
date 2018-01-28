#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

int main(){
	stack<char> first;
	stack<char> second;
	stack<int> result;

	char temp;
	int count = 0;
	while(count!=2 && scanf("%c",&temp)==1){
		if(temp!=32)
			first.push(temp);
		else
			count++;
	}

	count = 0;
	while(count !=2 && scanf("%c",&temp)==1){
		if(temp!=32 && temp!=10)
			second.push(temp);
		else
			count++;
	}

	int over = 0;
	while(!(first.empty() && second.empty())){
		int f=0,s=0;
		if(!(first.empty())){
			f = first.top()-'0';
			first.pop();
		}
		if(!(second.empty())){
			s = second.top()-'0';
			second.pop();
		}

		int temp = over+f+s;
		if(temp >= 10){
			over = 1;
			result.push(temp-10);
		}else{
			over = 0;
			result.push(temp);
		}
		//cout<< f<<"+"<<s<<"="<<temp<<endl;
	}

	if(over != 0)
		printf("%d",over);

	while(!result.empty()){
		printf("%d",result.top());
		result.pop();
	}
	printf("\n");

}
