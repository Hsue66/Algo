#include<cstdio>
#include<list>
#include<iostream>

using namespace std;

int main(){

	list<int> list1;
	list<int>::iterator iter;

	int size;
	scanf("%d",&size);

	for(int i=0; i<size; i++){
		int tmp;
		scanf("%d",&tmp);
		if(size < 3)
			list1.push_back(tmp);
		else
			list1.push_front(tmp);
	}

	cout<<list1.front()<<endl;
	for(iter=list1.begin(); iter != list1.end(); ++iter){
		printf("%d ",*iter);
	}
	cout<<endl;
	
	list1.sort();

	cout<<list1.back()<<endl;
	iter = list1.begin();
	++iter;
	//list1.erase(iter);
	
	list1.remove(6);
	for(auto it = list1.begin(); it != list1.end(); ++it){
		printf("%d ",*it);
	}
	cout<<endl;

}
