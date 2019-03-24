#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
	int testcase;
	scanf("%d",&testcase);

	for(int i=0; i<testcase; i++)
	{
		stack<char> STACK;
		char temp[10002];
		scanf("%s",temp);

		int size  = strlen(temp);
		int val = 0;
		int idx=0;
		while(idx<size)
		{
			// if open bracket - push
			if(temp[idx]=='(' || temp[idx]=='{' || temp[idx]=='[')
				STACK.push(temp[idx]);		
			// if stack empty - wrong
			else if(STACK.empty())
			{
				val = -1;
				break;
			}
			// if paired up - pop | else - wrong
			else
			{
				if(temp[idx]==']')
				{
					if(STACK.top()=='[')
						STACK.pop();
					else
					{
						val = -1;
						break;
					}
				}
				else if(temp[idx]=='}')
				{
					if(STACK.top()=='{')
						STACK.pop();
					else
					{
						val = -1;
						break;
					}
				}
				else if(temp[idx]==')')
				{
					if(STACK.top()=='(')
						STACK.pop();
					else
					{
						val = -1;
						break;
					}
				}
			}
			idx++;
		}

		if(!STACK.empty() || val == -1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
