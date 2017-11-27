#include <stdio.h>

int main(){
	int testcase;
	scanf("%d",&testcase);
	for(int i=0; i< testcase; i++){

	//while(1){
		int a,b;
	//while(scanf("%d%d",&a,&b) != EOF){
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d + %d = %d\n",i+1,a,b,a+b);
	}
}
