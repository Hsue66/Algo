#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
	string str;
	getline(cin,str);
	for(int i=0; i<str.length(); i++){
		if('a'<=str[i] && str[i]<='z'){
			int temp = str[i]+13;
			if(str[i] >'m'){
				temp =  temp%'z' + 'a' -1;
			}
			str[i] = temp;
		}
		else if('A'<=str[i] && str[i] <= 'Z'){
			str[i] = str[i]+13;
			if(str[i] >'Z')
				str[i] = str[i]%'Z' + 'A' - 1;
		}
	}

	cout<<str<<endl;

}
