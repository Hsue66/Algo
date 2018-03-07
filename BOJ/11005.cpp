#include<cstdio>
#include<stack>
//#include<iostream>

using namespace std;

int main(){
	int num, base;
	scanf("%d%d",&num,&base);
	
	stack<int> st;
	int div = num;

	do{
		st.push(div%base);
	//	cout<<div%base<<" "<<div/base<<endl;
		div = div/base;
	}while(div>0);
	//st.push(div);

	while(!st.empty()){
		if(st.top() >= 10)
			printf("%c",('A'+st.top()-10));
		else
			printf("%c",'0'+st.top());
		st.pop();
	}
	printf("\n");
	
}
