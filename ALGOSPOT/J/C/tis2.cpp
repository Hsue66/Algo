#include<stdio.h>
#include<math.h>

int numOftissue;
double min=987654321;	// to find minimum way
int minarr[10]={0};		// save minimum way

// save index and get index
class Node
{
	private:
		int x;
		int y;
	public:
		Node(){	}
		void setNode(int x1, int y1)
		{
			x=x1;
			y=y1;
		}

		int getX()
		{	return x;	}

		int getY()
		{	return y;	}

		void printNode()
		{
			printf("(%d,%d) -> ",x,y);
		}
};

Node nodes[10];			// arr of node
int visit[10]={0};		// check visited or not
int now[10] = {0};		// arr of present way

// find all case which can made by indexs
void findcase(int idx)
{
	if(idx >= numOftissue)
	{
		double temp = 0;
		for(int i=0; i<numOftissue-1; i++)
		{
			double value =	sqrt(pow(nodes[now[i]].getX()-nodes[now[i+1]].getX(),2.0)+pow(nodes[now[i]].getY()-nodes[now[i+1]].getY(),2.0));

			temp = temp+value;
		}

		double head =	sqrt(pow(0-nodes[now[0]].getX(),2.0)+pow(0-nodes[now[0]].getY(),2.0));
		double tail =	sqrt(pow(nodes[now[numOftissue-1]].getX()-10,2.0)+pow(nodes[now[numOftissue-1]].getY()-10,2.0));

		temp = temp + head + tail;
		
		// change min value and array
		if(temp<min)
		{
			min = temp;
			for(int i=0; i<numOftissue; i++)
				minarr[i] = now[i];
		}
		
		return;
	}

	// find case recursively
	for(int i=0; i<numOftissue; i++)
	{
		if(visit[i]==0)
		{
			now[idx]= i;
			visit[i]=1;
			findcase(idx+1);
			visit[i]=0;
		}
	}
}



int main()
{
	scanf("%d",&numOftissue);

	for(int i=0; i<numOftissue; i++)
	{
		int x,y;
		scanf("%d",&x);
		scanf("%d",&y);
		nodes[i].setNode(x,y);
	}

	// start to search
	findcase(0);
	
	// print result
	printf("(0,0) -> ");
	for(int i=0; i<numOftissue; i++)
		nodes[minarr[i]].printNode();
	printf("(10,10)\n");
}
