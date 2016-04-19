#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
	int testcase;
	scanf("%d%*c",&testcase);

	for(int i=0; i<testcase; i++)
	{
		stack<char> STACK;
		int val=0;
		char temp;
		do
		{
			scanf("%c",&temp);

			if(temp=='(' || temp=='{' || temp=='[')
				STACK.push(temp);
			else if(val != -1)
			{
				if(temp==']')
				{
					if(STACK.top()=='[')
						STACK.pop();
					else
						val=-1;
				}
				else if(temp=='}')
				{
					if(STACK.top()=='{')
						STACK.pop();
					else
						val=-1;
				}
				else if(temp==')')
				{
					if(STACK.top()=='(')
						STACK.pop();
					else
						val=-1;
				}
			}

		}
		while(temp!='\n');
		
		if(!STACK.empty())
			val = -1;

		if(val==-1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
