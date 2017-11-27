#include<stdio.h>
#include<iostream>

using namespace std;

int numOfdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char day[7][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

int main(){
	int month,date;
	scanf("%d%d",&month,&date);

	for(int i=0;i < month-1; i++)
		date = (date+numOfdays[i])%7;

	printf("%s\n",day[date]);
}
