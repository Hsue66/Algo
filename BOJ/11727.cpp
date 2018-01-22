#include<stdio.h>
using namespace std;

int num[1001] = {0};

int main(){
	int width;	
	scanf("%d",&width);
	num[0] = 1;
	num[1] = 1;

	int n = 2;
	while(!(n > width)){
		if(num[n] == 0)
			num[n] = (num[n-1]+2*num[n-2])%10007;
		n++;
	}
	printf("%d\n",num[width]);	
}
