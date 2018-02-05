#include<cstdio>
#include<iostream>
#include<list>

using namespace std; 

int main(){
	int num;
	scanf("%d",&num);

	list<pair<int,int> > Sum;
	list<pair<int,int> >::iterator iter;
	int MAX = 0;
	Sum.push_back(pair<int,int> (0,0));
	Sum.push_back(pair<int,int> (1001,0));

	for(; num>0; num--){
		int now;
		scanf("%d",&now);

		int before;

		for(iter = Sum.begin(); iter != Sum.end(); ++iter){
			if((*iter).first < now)
				before = (*iter).second;
		
			if((*iter).first == now){
				int val = before + now;
				if(val > (*iter).second){
					Sum.erase(iter);
					Sum.insert(++iter,pair<int,int> (now,val));
				}

				if(MAX < val)
					MAX = val;

				break;
			}
				
			if((*iter).first > now){
				int val = before + now;
				
				if(MAX < val)
					MAX = val;

				Sum.insert(iter,pair<int,int> (now,val));
				break;
			}
		}
	}

/*	for(iter = Sum.begin(); iter != Sum.end(); ++iter)
		cout<<(*iter).first<<" "<<(*iter).second<<endl;
	cout<<endl;
	*/	
	printf("%d\n",MAX);

}
