//HeapSort

#include <iostream>

using namespace std;
void max_heapify(int *a, int i, int size)
{
    int j, temp;
    temp = a[i];// putting the array in a temporary variable
    j = 2 * i;
    while (j <= size)
    {
        if (j < size && a[j+1] > a[j])//cecks if j is less than j+1
            j = j+1;// if j + 1 is bigger than j than set j eqaul to the bigger number
        if (temp > a[j])
            break;
        else if (temp <= a[j])// if temp is less than the j element
        {
            a[j/2] = a[j];// set it equal to j
            j = 2 * j; 
        }
    }
    a[j/2] = temp;
    return;
}
void heapsort(int *a, int size)
{
    int i, temp;
    for (i = size; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}
void build_maxheap(int *a, int size)//cuts it in half
{
    int i;
    for(i = size/2; i >= 1; i--)// goes through the whole array are backwards
    {
        max_heapify(a, i, size);// sends array, the place it is at in the array and the size of the array
    }
}
int main()
{
    int size, i, x;

    while(true){
        cin >> size;
        int a[size];
        if(size == 0)
             break;
        for (i = 1; i <= size; i++)
            {
                    cin>>a[i];
            }
            build_maxheap(a,size);
            heapsort(a, size);

            for (i = 1; i <= size; i++)
            {
                    cout<<a[i]<<endl;
            }


    }
    return 0;
 
}
