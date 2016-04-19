#include<stdio.h>
#include<map>

using namespace std;

int length=0;
map<int,int> MAP;
int qList[50002];
int total =0;
int sum=0;

void decideNerd(int now,int p, int q)
{
	map<int,int> MAP2;
	MAP2 =MAP;
	map<int,int>::iterator iter;

	MAP.insert(pair<int,int>(p,now));
	qList[now]=q;

	int flag =0;
	int temp = sum+1;

	for(iter=MAP.begin(); iter != MAP.end(); ++iter)
	{
		map<int,int>::iterator now_iter;

		if((*iter).second==now)
		{
			flag=1;
			now_iter = iter;
		}
		if(flag==0 && qList[(*iter).second]<qList[now])
		{
			temp--;
//			printf("qwer\n");
			MAP.erase(iter);
		}
		else if(flag==1 && qList[(*iter).second]>qList[now])
		{
			temp--;
//			printf("qwdder\n");
			//MAP.erase(now_iter);
			MAP =MAP2;
			break;
		}
	}

/*	int size = MAP.size();
	printf("%d\n",size);
	map<int,int>::iterator iter_map;
		for(iter_map=MAP.begin(); iter_map != MAP.end(); ++iter_map)
			printf("%d ",(*iter_map).second);
	printf("tempi: %d\n",temp);
*/	sum = temp;
	total = total+temp;
}

int main()
{
	int testcase;
	scanf("%d",&testcase);

	for(int i=0; i<testcase; i++)
	{
		scanf("%d",&length);
		for(int j=0; j<length; j++)
		{
			int p,q;
			scanf("%d",&p);
			scanf("%d",&q);
			
			decideNerd(j,p,q);
		}

		printf("%d\n",total);
		// clear variables
		MAP.clear();
		total =0;
		sum =0;
		for(int j=0; j<length;j++)
			qList[j]=0;
	}

}
