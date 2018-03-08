#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	string binary;
	cin >> binary;

	int len = binary.length();
//	cout<<len<<endl;
	int left = len%3;
	int quot = len/3;
	
	int idx = 0;
	if(left != 0){
		int now = 0;
		for(int i=0; i<left; i++)
			now = binary[idx++]-'0'+ now*2;
		printf("%d",now);
	}

	while(quot--){
		int now = 0;
		for(int i=0; i<3; i++)
			now = binary[idx++]-'0'+ now*2;
		printf("%d",now);
	}
	printf("\n");
}
