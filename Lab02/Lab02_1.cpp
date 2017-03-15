#include <iostream>
using namespace std;
//linear
//linear algorithm function
int LinAlgoFunct(int arr[], int n, int m){
	for(int i = 0; i < n; i++){
		if(arr[i] == m){
			return i;
		}
			
	}return -1;
	
}
     
int main() {
	int input, size = 0;
	//cout << "Please enter the size of the array \n";
	
	
	//cout << "Enter the value to be searched \n";
	
	while(true){
		//int *arr = new int [size];
		cin >> size;
		int arr[size];
		if(size == 0)
				break;
		cin >> input;
		for(int i = 0; i < size; i++){
			cin >> arr[i]; 
			}
		//cin >> input;	

		int output = LinAlgoFunct(arr, size, input);
		cout << output << "\n";

	}
	
	
	return 0;
}
