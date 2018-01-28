#include <cstdio>
#include <iostream>

using namespace std;

#define SIZE 100000
int main(){
	int numOfcoms;
	scanf("%d",&numOfcoms);
	int queue[SIZE];
	int first = 0;
	int last = -1;
	
	while(numOfcoms--){
		char command[6];
		scanf("%s",command);

		if(strcmp(command,"push")==0){
			int num;
			scanf("%d",&num);
			if(last+1 < SIZE)
				queue[++last] = num;
		}
		else if(strcmp(command,"pop")== 0){
			if(first-last == 1)
				printf("-1\n");
			else
				printf("%d\n",queue[first++]);
		}
		else if(strcmp(command,"size")== 0){
			printf("%d\n",last+1-first);
		}
		else if(strcmp(command,"empty")== 0){
			if(last+1-first == 0 )
				printf("1\n");
			else
				printf("0\n");
		}
		else if(strcmp(command,"front")== 0){
			if(last+1-first == 0)
				printf("-1\n");
			else
				printf("%d\n",queue[first]);
		}
		else if(strcmp(command,"back")== 0){
			if(last+1-first == 0)
				printf("-1\n");
			else
				printf("%d\n",queue[last]);
		}
/*
		cout<<"first: "<< first<<" ,last: "<<last<<endl;
		for(int i =0; i<SIZE; i++){
			cout<<queue[i]<<" ";
		}
		cout<<endl;
		*/
	}
}
