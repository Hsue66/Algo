#include<stdio.h>
#include<string.h>
#include<map>
#include<list>

using namespace std;


int main()
{
	int alpha[26]={0};		// array of alphabet
	char string[1000000];	// array of input

	scanf("%s",string);

	// count
	int length = strlen(string);
	for(int i=0; i<length; i++)
		alpha[int(string[i])-65]++;

	map<int,list<int> > order;
	map<int,list<int> >::iterator iter;
	list<int>::iterator iter_l;

	// make map
	for(int i=0; i<26; i++)
		order[alpha[i]].push_back(i+65);

	// print	
	for(iter=order.begin(); iter != order.end(); ++iter)
	{
		for(iter_l=(*iter).second.begin(); iter_l!=(*iter).second.end(); ++iter_l)
		{
			for(int idx=0; idx<(*iter).first; idx++)
				printf("%c",(*iter_l));
		}
	}
	printf("\n");
}
