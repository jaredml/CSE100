#include <iostream>
using namespace std;

int BinarySearch(int Arr[], int begin, int end, int key)
{

	while (end >= begin) 
	{
	int center;
	center = (end + begin) / 2; 		//find where is the center 
	
	if (Arr[center] == key) 
		return center;
	else if (Arr[center] <key)		
		return BinarySearch(Arr, (center + 1), end, key);
	else						
		//(Arr[center] > key) 			
		return BinarySearch(Arr, begin, (center - 1), key);
	}
	return -1;
}


int main(){

	int n, key, result;
	//cout<<"Enter the size: \n";
	cin>> n;

	
	while(n!=0){
	//cout<<"Enter int To Search in the Array";
	cin>>key;

	int *Arr=new int [n];
	for (int i=0; i<n; i++)
		cin>> Arr[i];

	
	result= BinarySearch(Arr, 0, n-1, key);
	cout<<result<<endl;

	
	cin>>n;
	}
	
	return 0;
}
