#include <iostream>
#include <list>
#include <math.h>
using namespace std;

void BucketSort(float a[], int size);
void print(const list<string>& s);
int main() {

	int size = -1;
	float input = 0;

	while(size != 0) {
		cin >> size;
		float *a = new float[size];//points to the array
		
		
		for(int i = 0; i < size; i++){
	    		cin >> input;//filling the array with values
            		a[i] = input;
        	}

		//Call Sorting algorithm
		BucketSort(a, size);
		
		//clear arr for next iteration
		delete [] a;
	}
}

void print(const list<float>& s)
{
	
	list<float>::const_iterator i;
	for( i = s.begin(); i != s.end(); ++i)//iterate through the temporary list 
		cout << *i << endl; //print it
}

void BucketSort(float arr[], int size){
	
	list<float> *Bucket;
	list<float> Temp;

	//The Bucket list
	Bucket = new list<float>[size];
	int x;
	
	//Sort to different buckets
    //size # of buckets
	for(int i = 0; i < size; i++){
		x = floor(size*arr[i]);
		Bucket[x].push_back(arr[i]);
	}
	
	
	for(int i = 0; i < size; i++){
		Bucket[i].sort();//Sort Each Bucket
	}
	
	
	for(int i = 0; i < size; i++){
		Temp.insert(Temp.end(),Bucket[i].begin(), Bucket[i].end());//put sorted buckets into temp
	}

	
	print(Temp);//print sorted list
	
	
	delete [] Bucket;//clears buckets so there are no memory leaks	
}
