#include <iostream>
using namespace std;

int main(){
  int num;
  //cout<<"Enter the n: \n";
	cin>> num;
  
  while(num != 0){
	  int *a = new int [num];
		for (int i = 0; i < num; i++)
			cin >> a[i];
		
	mergesort(a,0,(num-1));
	
	for (int i = 0; i < num;i++){
		cout << a[i] << endl;
	}
	
	cin >> num;

  }
return 0;

} 


void merge(int a[] , int low, int high, int mid){
	int l1,j,l2;
	int *c = new int [high+1];
	l1 = low;
	l2 = low;
	j = mid + 1;
	
	while (l1 <= mid && j <= high)
    {
        if (a[l1] < a[j])
        {
            c[l2] = a[l1];
            l2++;
            l1++;
        }
        else
        {
            c[l2] = a[j];
            l2++;
            j++;
        }
    }
    while (l1 <= mid)
    {
        c[l2] = a[l1];
        l2++;
        l1++;
    }
    while (j <= high)
    {
        c[l2] = a[j];
        l2++;
        j++;
    }
    for (l1 = low; l1 < l2; l1++)
    {
        a[l1] = c[l1];
    }
}

void mergesort (int a[], int low, int high){
	int mid;
	if(low < high){
		mid=(low + high)/2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, high, mid);
	}
	return;
}



