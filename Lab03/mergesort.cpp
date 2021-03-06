//mergesort
#include <iostream>
using namespace std;

template <class T>
void merge_sort(T array[],int beg, int end){
    if (beg == end){
        return;
    }
    int mid = (beg+end)/2;
    merge_sort(array,beg,mid);
    merge_sort(array,mid+1,end);
    int i = beg,j = mid+1;
    int l = end-beg+1;
    T *temp = new T [l];
    for (int k = 0;k < l; k++){
        if (j > end || (i <= mid && array[i] < array[j])){
            temp[k] = array[i];
            i++;
        }
        else{
            temp[k] = array[j];
            j++;
        }
    }
    for (int k = 0,i = beg; k<l; k++, i++){
        array[i] = temp[k];
    }
    delete temp;
}

int main() {
    
    int i, n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    int array[n];
    cout << "Enter elements\n";
    while(n > 0){
    int l = sizeof(array)/sizeof(array[0]);
      merge_sort(array, 0, l-1);
      cout << "Result:\n";
      for (k = 0;k < l; k++){
        cout << array[k] << endl;
        }
        cin >> n;
    }
    return 0;
}
