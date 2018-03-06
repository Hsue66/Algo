#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase>0){
		testcase--;
		int big,small;
		scanf("%d%d",&big,&small);

		if(small>big){
			int t = big;
			big = small;
			small = t;
		}
		
		int diff = big-small;

		int gcd=0;
		int lcm=0;
		for(int div=1; div <= diff; div++){
			if(diff%div == 0){
				gcd = diff/div;
				if(small%gcd == 0)
					lcm = big *(small/gcd);
			}
			if(gcd != 0 && lcm != 0)
				break;
		}

//	printf("%d\n",gcd);
		if(diff != 0)
			printf("%d\n",lcm);
		else
			printf("%d\n",small);
	
	}
}
