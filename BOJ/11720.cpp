#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int testcase;
	scanf("%d%*c",&testcase);
	int total = 0;
	char tmp[100];
	for(int i = 0; i<testcase; i++){
		scanf("%c",&tmp[i]);
		total += (tmp[i]-'0');
	}
	printf("%d\n",total);
}
