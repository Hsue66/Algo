#include<stdio.h>
#include<list>

using namespace std;
class Node
{
	private:
		int value;
		int best;
		int parent;
	public:
		Node()
		{
			best=987654321;
		}
		void setValue(int val)
		{
			value = val;
		}
		int getValue()
		{
			return value;
		}

		void setBest(int temp)
		{
			if(temp>=100)
				best=100;
			else if(best>temp)
				best = temp;	
		}

		int getBest()
		{
			return best;
		}

		void setParent(int idx)
		{
			parent = idx;
		}

		int getParent()
		{
			return parent;
		}
};

int length;
Node nodes[100];
list<int>::iterator open_i;
list<int> close;
list<int>::iterator close_i;

void search(int current)
{
	if(current != length-1)
	{
		// save surround index
		list<int> open;
		int surround[4] = {current-1,current-length,current+length,current+1};

		if(current%length==0)
		{
			for(int i=1; i<4;i++)
			{
				if( !(surround[i]>length*length-1) && !(surround[i]<0) && !(nodes[current].getParent()==surround[i]))
					open.push_back(surround[i]);
			}
		}
		else if(current%length==length-1)	
		{
			for(int i=0; i<3;i++)
			{
				if( !(surround[i]>length*length-1) && !(surround[i]<0) && !(nodes[current].getParent()==surround[i]))
					open.push_back(surround[i]);
			}
		}
		else
		{
			for(int i=0; i<4;i++)
			{
				if( !(surround[i]>length*length-1) && !(surround[i]<0) && !(nodes[current].getParent()==surround[i]))
					open.push_back(surround[i]);
			}	
		}
		for(open_i=open.begin(); open_i!=open.end(); ++open_i)
			printf("%d ",(*open_i));
		printf("\n");

		// set best n parent, move to close list
		for(open_i=open.begin(); open_i!=open.end(); ++open_i)
		{
			nodes[(*open_i)].setBest((nodes[current].getBest()+nodes[(*open_i)].getValue()));
			nodes[(*open_i)].setParent(current);
			close.push_back((*open_i));
			search(*open_i);
		}

	}
	else
		return;


}

int main()
{
	scanf("%d",&length);

	// save in Node
	for(int i=0; i<length; i++)
	{
		char temp[length];
		scanf("%s",temp);
		for(int j=0; j<length; j++)
			nodes[i*length+j].setValue(int(temp[j])-48);
	}

	nodes[(length-1)*length].setBest(0);
	nodes[(length-1)*length].setParent(987654321);
	search((length-1)*length);

	printf("%d\n",nodes[length-1].getBest());
/*	for(int i=0; i<length*length; i++)
		printf("%d ",nodes[i].getValue());
*/
}
