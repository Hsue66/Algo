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
//				printf("%d\n",j);
//				fflush(stdout);
			}
		}

		

		int count =0;
		while(!st.empty())
		{
			char temp = disk[st.top()];

			if(temp == num2[0])
			{
				for(int i=1; i<digit; i++)
				{
					if(disk[(st.top()+i)%part] < num2[i])
					{
						count++;
						break;
					}
					else if(disk[(st.top()+i)%part] == num2[i])
					{
						if(i==digit-1)
							count++;
						else
							continue;
					}
					else
						break;					
				}
			}
			else
			{
				for(int i=1; i<digit; i++)
				{
					if(disk[(st.top()+i)%part] > num1[i])
					{
						count++;
						break;
					}
					else if(disk[(st.top()+i)%part] == num1[i])
					{
						if(i==(digit-1))
							count++;
						else
							continue;
					}
					else
						break;
				}
				
			}
			
			st.pop();
		}
		printf("%d\n",count);
		fflush(stdout);

		free(num1);
		free(num2);
		free(disk);
	}
}
