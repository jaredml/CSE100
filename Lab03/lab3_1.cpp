#include <iostream>

using namespace std;

void insertSort(int a[], int length) {

      int i, j, temp;

      for (i = 1; i < length; i++) {

            j = i;
            while (j > 0 && a[j - 1] > a[j]) {
                  temp = a[j];
                  a[j] = a[j - 1];
                  a[j - 1] = temp;
                  j--;
            }
      }
}

int main(){
  int num;
  //cout<<"Enter the size: \n";
	cin >> num;
  
  while(num != 0){
	  int *a = new int [num];
		for (int i = 0; i < num; i++)
			cin >> a[i];
	  
  insertSort(a, num); //sorting process using insertion sort
  
	for(int i = 0; i < num;i++)
    		cout<< a[i] << endl; //after sorting

	cin >> num;

  }
return 0;

} 
