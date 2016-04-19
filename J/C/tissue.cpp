#include<stdio.h>

int numOftissue;

class Node
{
	private:
		int x;
		int y;
	public:
		Node(int X,int Y)
		{
			x=X;
			y=Y;
		}
};

int main()
{
	scanf("%d",&numOftissue);

	for(int i=0; i<numOftissue; i++)
	{
		int x,y;
		scanf("%d",&x);
		scanf("%d",&y);

		Node node(
	}
}
