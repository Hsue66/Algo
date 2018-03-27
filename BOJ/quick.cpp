#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

long long a[5000001];


void quick(long long arr[],int first, int last){
	long long flag = arr[last-1];
	
	int cent = first;
	for(int i=first; i<last-1; i++){
		if(flag > arr[i]){
			int temp = arr[cent];
			arr[cent] = arr[i];
			arr[i] = temp;
			cent++;
		}
	}
	int temp = arr[cent];
	arr[cent] = arr[last-1];
	arr[last-1] = temp;

	if(first < cent-1)	
		quick(arr,first,cent);
	if(cent+1 < last)
		quick(arr,cent+1,last);
	/*for(int i=first; i<last; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	*/
}


int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
		scanf("%lld",&a[i]);
	
	quick(a,0,n);

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
