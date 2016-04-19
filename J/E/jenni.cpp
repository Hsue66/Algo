#include<stdio.h>
#include<string.h>
#include<list>

using namespace std;
char string[10001];
int length;
list<int> check[12];
char jenni[12]={'J','E','N','N','I','F','E','R','S','O','F','T'};

// check same alphabet with jenni
void checkString()
{
	for(int i=0; i<length; i++)
	{
		for(int j=0; j<12; j++)
		{
			if(string[i]==jenni[j])
				check[j].push_back(i);
		}
	}
}

int longest=0;
int jennifer[12];

void makeJenni()
{
	int templong=0;
	int tempjennifer[12];
	memset(tempjennifer,-1,12*sizeof(int));

	int before=0;
	for(int i=0; i<12; i++)
	{
		list<int>::iterator check_i;
		for(check_i=check[i].begin(); check_i!=check[i].end(); ++check_i)
		{
			if(before<(*check_i))
			{
				templong++;
				tempjennifer[i]=(*check_i);
				before = (*check_i);
				printf("%d %d\n",templong,before);
			}
		}
	}
	if(templong>longest)
	{
		for(int i=0; i<12; i++)
		{
			jennifer[i]=tempjennifer[i];
			printf("%d ",jennifer[i]);
		}
	}
}

int main()
{
	scanf("%s",string);
	length = strlen(string);

	checkString();

	makeJenni();

	/*
	list<int>::iterator iter_l;
	for(int i=0; i<12; i++)
	{
		for(iter_l=check[i].begin(); iter_l!=check[i].end(); ++iter_l)
			printf("%d ",(*iter_l));
		printf("\n");
	}
*/
	printf("%s",string);
}
