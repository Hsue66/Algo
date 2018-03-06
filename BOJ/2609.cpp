#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
	int big,small;
	scanf("%d%d",&big,&small);

	if(small>big){
		int t = big;
		big = small;
		small = t;
	}
	int gcd=0;
	int lcm=0;
	for(int div=1; div <= small; div++){
		if(small%div == 0){
			gcd = small/div;
			if(big%gcd == 0)
				lcm = div * big;
		}
		if(gcd != 0 && lcm != 0)
			break;
	}

	printf("%d\n",gcd);
	printf("%d\n",lcm);
}
