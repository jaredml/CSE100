#include <iostream>
#include <queue>

using namespace std;

const int INPUT_SIZE = 20;
const int BUCKET_K = 10;

void print(int *input)
{
    for ( int i = 0; i < INPUT_SIZE; i++ )
        cout << input[i] << " ";
    cout << endl;
}

int hash(int n)
{
    return n/5;
}

void doinsertionsortforbucket(int* input, int len)
{
    while( len-- > 0) {
        if (input[len] > input[len+1]) {
            int tmp = input[len];
            input[len] = input[len+1];
            input[len+1] = tmp;
        } else
            return;
    }
}

void bucketsort(int* input)
{
    queue<int> *buckets[BUCKET_K];
    for ( int i = 0; i < BUCKET_K; i++ )
        buckets[i] = new queue<int>;

    // Hash the input and insert the content into appropriate bucket based on hash.
    for (int i=0;i<INPUT_SIZE;i++)
    {
        int hashValue = hash(input[i]);
        if (hashValue >= BUCKET_K)
            hashValue = BUCKET_K-1;

        buckets[hashValue]->push(input[i]);
    }

    // extract the content from each of the buckets in order.
    // using insertion sort
    int outputidx = 0;
    for ( int i = 0; i < BUCKET_K; i++ )
    {
        if (buckets[i]->size() == 1) {
            input[outputidx++] = buckets[i]->front();
            cout << buckets[i]->front() << " | ";
            buckets[i]->pop();
        }
        if (buckets[i]->size() > 1)
        {
            while (!buckets[i]->empty())
            {
                input[outputidx] = buckets[i]->front();
                doinsertionsortforbucket(input, outputidx);
                cout << buckets[i]->front() << " ";
                buckets[i]->pop();
                outputidx++;
            }
            cout << "| ";
        }
    }
    // clear buckets.
    for ( int i = 0; i < BUCKET_K; i++ )
        delete buckets[i];

}

int main()
{
    
    int size = 0;
    cin >> size;
    while(size != 0){
   	int input[size];
	for(int i = 0; i < size; i++){
		cin >> input[i];
		bucketsort(input);
	}
    	
        print(input[size]);
	cin >> size;
    }
    //cout << "Input: ";
    //print(input);
    //cout << "Bucketed list: " ;
    
    //cout << "\nOutput: ";
    //print(input);
    return 0;
}


