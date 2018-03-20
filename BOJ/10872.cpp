#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	
	int val = 1;
	if(num==0)
		printf("%d\n",val);
	else{
		while(num--)
			val *= (num+1);
	
		printf("%d\n",val);
	}
}
