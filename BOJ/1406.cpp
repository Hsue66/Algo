#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main(){
	char str[600000];
	scanf("%s%*c",str);
	int size = strlen(str);
	int cursor = size;
	
	int loop;
	scanf("%d%*c",&loop);
	
	stack<char> saveStack;

	while(loop--){
		char command;
		scanf("%c%*c",&command);

		if(command == 'L'){
			if(cursor > 0){
				cursor--;
				saveStack.push(str[cursor]);
			}
		}
		else if(command == 'D'){
			if(size > cursor){
				str[cursor] = saveStack.top();
				saveStack.pop();
				cursor++;
			}
		}
		else if(command == 'B'){
			if(cursor > 0){
				cursor--;
				size--;
			}
		}
		else{
			char addChar;
			scanf("%c%*c",&addChar);

			str[cursor] = addChar;
			cursor++;
			size++;
		}
	
		/*	
		cout<<cursor<<" ";
		for(int i=0; i<cursor; i++)
			cout<<str[i]<<" ";
		cout<<endl;
		*/
	}

	for(int i=0; i<cursor; i++)
		printf("%c",str[i]);
	while(saveStack.empty() == 0){
		printf("%c",saveStack.top());
		saveStack.pop();
	}
	printf("\n");
}
