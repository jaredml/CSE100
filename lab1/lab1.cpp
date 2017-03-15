#include <iostream>	
using namespace std; 

void reverse(int a[], int num){
	int t, j;
	for (j = 0; j < num/2; ++j) {
    		t = a[num-j-1];
    		a[num-j-1] = a[j];
   		a[j] = t;
	}
}

int main(void)
{
	int num;
	cin >> num;
	
	while(num!=0){	
	int *a = new int [num];
	
	for (int i = 0; i < num; i++){
		cin >> a[i];	//gets the inputs
	}
	
	bool increasing = true;
	for (int i = 1; i < num; i++)  // checks if it is decreasing
		if (a[i-1] > a[i]){
		increasing = false;
		break;
		}
	
	if (increasing == true) {
		reverse(a, num);
		
		for (int i = 0; i < num; i++)
			cout << a[i] << endl; 
	}

	else 
		cout << "INCORRECT SEQUENCE" <<endl;


	cin >> num;

	}

	return 0;
}

