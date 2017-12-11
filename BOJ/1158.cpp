#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int numOfpeople;
	int value;
	scanf("%d%d",&numOfpeople,&value);
	queue<int> circleList;
	
	int i=0;
	while(i++ < numOfpeople)
		circleList.push(i);

	printf("<");	
	while(!circleList.empty()){
		for(int i=0; i<value; i++){
			if(i == value-1){
				printf("%d",circleList.front());
				circleList.pop();
				if(!circleList.empty())
					printf(", ");
			}
			else{
				circleList.push(circleList.front());
				circleList.pop();
			}
		}
	}
	printf(">\n");
/*	
	for(int i=0; i<size; i++){
		cout<<circleList.front()<<" ";
		circleList.pop()
	}
	cout<<endl;*/
}
