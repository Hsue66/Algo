#include<cstdio>
#include<cmath>

using namespace std;
int arr[1000001];

int main(){
	int lower,upper;
	scanf("%d%d",&lower,&upper);

	int range = sqrt(upper)+1;
	for(int i=2; i<range; i++){
		if(arr[i] != 1){
			if(i>= lower)
				printf("%d\n",i);
			int start = lower/i;
			while(start*i <= upper){
				arr[start*i] = 1;
				start++;
			}
		}
	}
	
	for(int idx=lower; idx <=upper; idx++){
		if(arr[idx] != 1 && idx != 1)
			printf("%d\n",idx);
	}
}
