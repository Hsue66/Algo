#include<cstdio>
#include<iostream>
#define DIV 1000000
using namespace std;

int cnt[5001]={0};

int main(){
	string str;
    cin >> str;

    int len = str.size();
    str = " " + str;
    cnt[0] = 1;

	for(int j=1; j<= len; j++){
	//	cout<<endl<<str[j]<<" ";
		if(str[j]-'0' >= 1)
			cnt[j] = (cnt[j] + cnt[j-1]) % DIV;
		
		if(j==0)
			continue;

		if(str[j-1]-'0' == 0)
			continue;
		
		int temp = (str[j-1]-'0')*10 + (str[j]-'0');
		if(10<=temp && temp <= 26)
			cnt[j] = (cnt[j] + cnt[j-2]) % DIV;
	//	cout<<cnt[j];
	}
	
	printf("%d\n",cnt[len]);

}
