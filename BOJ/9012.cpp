#include<stdio.h>

int main(){
	int testcase;
	scanf("%d%*c",&testcase);
	while(testcase--){
		int top = 0;
		int wrong = 0;
		char piece = 0;
		while(piece != 10 && scanf("%c",&piece)==1){
			if(piece == '(')
				top++;
			else if(piece == ')'){
				if(top == 0)
					wrong = 1;
				else
					top--;
			}
		}
		if(top != 0)
			wrong = 1;

		if(wrong)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
