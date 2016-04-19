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
int visit[12]={0};
int templong=0;
int tempjennifer[12];


void find()
{
}

void findcase()
{
	for(int i=0; i<12; i++)
	{
		list<int>::iterator check_i;
		if(check[i].size()==0)
			visit[i]==1;
		for(check_i=check[i].begin(); check_i!=check[i].end(); ++check_i)
		{
			if(visit[i]==0)
			{
			tempjennifer[i]=(*check_i);
			visit[i]=1;
			findcase(idx+1);
			visit[i]=0;
			}
		}
	}
	for(int i=0; i<12; i++)
			printf("%d ",tempjennifer[i]);
		printf("\n");

		
}

void makeJenni()
{
	memset(tempjennifer,-1,12*sizeof(int));
	findcase(0);
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
