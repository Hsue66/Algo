#include<cstdio>
#include<stack>
//#include<iostream>

using namespace std;

int main(){
	int baseA,baseB;
	scanf("%d%d",&baseA,&baseB);
	int num;
	scanf("%d",&num);
	int sum = 0;
	while(num--){
		int temp;
		scanf("%d",&temp);
		sum = sum*baseA + temp;
	}
//	cout<<sum<<endl;
	stack<int> st;
	do{
		st.push(sum%baseB);
		sum = sum/baseB;
	}while(sum>0);

	while(!st.empty()){
		printf("%d",st.top());
		st.pop();
		if(!st.empty())
			printf(" ");
	}
	printf("\n");
}
