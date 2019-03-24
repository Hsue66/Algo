#include<stdio.h>
#include<map>
#include<list>


using namespace std;

int main()
{
	map<int,int> MAP;
	map<int,int>::iterator iter;

	MAP.insert(pair<int,int>(3,65));
	MAP.insert(pair<int,int>(3,64));
	MAP.insert(pair<int,int>(1,70));
	MAP.insert(pair<int,int>(2,63));

//	for(iter=MAP.begin(); iter != MAP.end(); ++iter)
//		printf("%d ",(*iter).second);

	list<int> list1;
	list<int>::iterator iter_l;

	list1.push_back(65);
	list1.push_back(63);
	list1.push_back(75);
	list1.push_back(67);
	list1.push_back(65);
	list1.push_back(62);

	for(iter_l=list1.begin(); iter_l != list1.end(); ++iter_l)
		printf("%d ",(*iter_l));

	printf("\n");
	list1.sort();

	for(iter_l=list1.begin(); iter_l != list1.end(); ++iter_l)
		printf("%d ",(*iter_l));



}

