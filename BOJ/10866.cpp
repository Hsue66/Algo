#include <cstdio>
#include <cstring>

using namespace std;

#define SIZE 20002
int main(){
	int numOfcoms;
	scanf("%d",&numOfcoms);
	int deque[SIZE];
	int first = SIZE/2;
	int last = SIZE/2;
	
	while(numOfcoms--){
		char command[11];
		scanf("%s",command);

		if(strcmp(command,"push_front")==0){
			int num;
			scanf("%d",&num);
			
			deque[first--] = num;
		}
		else if(strcmp(command,"push_back")==0){
			int num;
			scanf("%d",&num);

			deque[++last] = num;
		}
		else if(strcmp(command,"pop_front")== 0){
			if(first == last)
				printf("-1\n");
			else{
				printf("%d\n",deque[++first]);
			}
		}
		else if(strcmp(command,"pop_back")== 0){
			if(first == last)
				printf("-1\n");
			else{
				printf("%d\n",deque[last--]);
			}
		}
		else if(strcmp(command,"size")== 0){
			int size;
			if(first <= last)
				size = last-first;

			printf("%d\n",size);
		}
		else if(strcmp(command,"empty")== 0){
			if(last-first == 0 )
				printf("1\n");
			else
				printf("0\n");
		}
		else if(strcmp(command,"front")== 0){
			if(last-first == 0)
				printf("-1\n");
			else
				printf("%d\n",deque[first+1]);
		}
		else if(strcmp(command,"back")== 0){
			if(last-first == 0)
				printf("-1\n");
			else
				printf("%d\n",deque[last]);
		}
/*
		cout<<"first: "<< first<<" ,last: "<<last<<endl;
		for(int i =0; i<SIZE; i++){
			cout<<deque[i]<<" ";
		}
		cout<<endl;
	//	*/
	}
}
