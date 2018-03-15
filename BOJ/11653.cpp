#include<cstdio>
#include<queue>
//#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);

	int div = 2;
	queue<int> que;
	do{
		if(num%div == 0){
			que.push(div);
			num = num/div;
		}
		else
			div++;
	}while(num!=1);

	while(!que.empty()){
		printf("%d\n",que.front());
		que.pop();
	}
}
