#include<cstdio>

int main(){
	char piece;
	int numStack[100000];
	int top = 0;
	int razer = 0;
	int total = 0;
	while(piece != 10 && scanf("%c",&piece)==1)
	{
	/*
		cout<<"Stack, t "<<top<<" : "<<endl;
		for(int i=0; i<top; i++)
			cout<<numStack[i]<<" ";
		cout<<endl;
	*/
		if(piece == '('){
			razer = 0;
			numStack[top++] = 0;
		}
		else if(piece == ')'){
			top--;
			if(razer == 0){
				razer = 1;
				numStack[top-1]++;
			}
			else{
				total += numStack[top]+1;
				numStack[top-1] += numStack[top];
			}
		}
	}
	printf("%d\n",total);
}
