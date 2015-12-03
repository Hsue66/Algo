# include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main()
{
	int pnum;
	int count=0;
	scanf("%d",&pnum);
	
	for(int i=0; i<pnum; i++)
	{
		int part,digit;
		int big=0;
		stack<int> st;

		scanf("%d %d",&part,&digit);
		
		char* num1 = (char*)malloc(sizeof(char)*digit);
		char* num2 = (char*)malloc(sizeof(char)*digit);
		char* disk = (char*)malloc(sizeof(char)*part);
		
		getchar();
		for(int i=0; i<digit; i++)
		{
			scanf("%c",&num1[i]);
			getchar();
		}
			
		for(int i=0; i<digit; i++)
		{
			scanf("%c",&num2[i]);
			getchar();
		}

		for(int i=0; i<part; i++)
		{
			scanf("%c",&disk[i]);
			getchar();
		}
		
//		printf("%s\n",num1);
//		printf("%s\n",num2);
//		printf("%s\n",disk);
//		fflush(stdout);	

		for(int j=0; j<part; j++)
		{
			if(num1[0] <= disk[j] && disk[j] <= num2[0])
			{	st.push(j);
			}
		}

		

		int count =0;
		stack<int> s2;
		while(!st.empty())
		{
			for(int i=0; i<digit; i++)
			{
			char temp = disk[(st.top()+i)%part];
				if(temp == num2[i])
				{
					if(i == digit-1)
					{
						s2.push(st.top());
						break;
					}
					else
						continue;
				}
				else if(temp < num2[i])
				{
					s2.push(st.top());
					break;
				}
				else
					break;
			}
			st.pop();
		}

		while(!s2.empty())
		{
			for(int i=0; i<digit; i++)
			{
			char temp = disk[(s2.top()+i)%part];
				if(temp == num1[i])
				{
					if(i == digit-1)
					{
						count++;
						break;
					}
					else
						continue;
				}
				else if(temp > num1[i])
				{
					count++;
					break;
				}
				else
					break;
			}
			s2.pop();
		}
	
			printf("%d\n",count);
			fflush(stdout);

		free(num1);
		free(num2);
		free(disk);
	}
}
