#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> vec1;
	vector<int>* vec2 = new vector<int>;

	int size;
	scanf("%d",&size);

	for(int i=0; i<size; i++){
		int tmp;
		scanf("%d",&tmp);
		vec1.push_back(tmp);
	}

	for(int i=0; i<size; i++)
		cout<<vec1[i]<<" ";
	cout<<endl;

	for(auto it = vec1.begin(); it != vec1.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;

}
