#include<cstdio>
//#include <iostream>

using namespace std;

long long Cnt[31];

int main(){
	int num;
	scanf("%d",&num);
	
	if(num%2 == 1)
		printf("0\n");
	else{
		Cnt[0] = 1;
		for(int i=1; i<num+1; i++){
			if(i%2 == 1)
				Cnt[i] = 0;
			else{
				int sum = 0;
				for(int j=1; j<=i/2; j++){
					if(j==1)
						sum += 3*Cnt[i-j*2];
					else
						sum += 2*Cnt[i-j*2];
				}
				Cnt[i] = sum;
			}
		}
		printf("%lld\n",Cnt[num]);
	}
}
