#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;

	while(!getline(cin,str).eof()){
		int low=0;
		int up=0;
		int num = 0;
		int blank = 0;
		for(int i=0; i<str.length(); i++)
		{
			if(48 <= str[i] && str[i] <= 57)
				num++;
			else if(65 <= str[i] && str[i] <=90)
				up++;
			else if( 97 <= str[i] && str[i] <= 122)
				low++;
			else
				blank++;
		}
		printf("%d %d %d %d\n",low,up,num,blank);
	}
}
