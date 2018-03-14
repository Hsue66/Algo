#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	int flag = num;
	while(num--){
		int val;
		scanf("%d",&val);
		if(val == 1)
			flag--;
		else{
			for(int i=2; i<val; i++){
				if(val%i == 0){
					flag--;
					break;
				}
			}
		}
	}
	printf("%d\n",flag);
}
