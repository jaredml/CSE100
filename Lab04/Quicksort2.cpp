#include <iostream>
#include <iomanip>

using namespace std;

 void quickSort(int arr[], int left, int right)
 {
  int i = left, j = right;
  int tmp;
  int pivot = arr[right];

  /* partition */
  while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
              }
    }//recursively sorts the numbers because im lazy
    if (left < j)
    quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main()
{
    int size, l, h, i;

    
    
    while(true){                  
            cin >> size;
            int a[size];
            
            for(i = 0;i < size ;i++){
                  cin >> a[i];
            }
            //cout << "boobs" << endl;   
            h = size - 1;
            l = 0;
            quickSort(a, l, h);
            //cout << "boobs" << endl;
            for(i = 0;i < size; i++)
            {
                      cout << a[i] << endl;  
            }
            if(size == 0)
                       break;
      }
}
