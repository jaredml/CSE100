#include <iostream>

using namespace std;

int HashFunc(int x, int index) 
{
	int h1 = x % 13; //h1(k) = k
	int h2 = 1 + (x % 11); //h2(k) = 1 + (k mod 11)

	int h = (h1 + (index * h2)) % 13;  //h(k, i) = (h1(k) + ih2(k))
 	
	return h;
}

//double hashing function
void HashInsert(int hSize[], int x) 
{
    int index = 0;
	int hash = 0;
	bool check = false;
	while((index < 13) && !check)
	{	
		hash = HashFunc(x, index);
        	if(hSize[hash] == -1)
		{
			check = true;
		    	hSize[hash] = x;
		}
		index++;
	}
}


int HashSearch(int hSize[], int x) 
{
        int i = 0;
	
    	for(int j = 0; j < 13; j++)
    	{
        	i = HashFunc(x, j);
		    if(hSize[i] == x)
		    {
                  return i;
		    }
    	}
	if(hSize[i] != -1)
	{
		return -1;
	}
}	


void HashDelete(int hSize[],int x)
{

int toDelete = HashSearch(hSize, x);
    	if(toDelete != -1)
    	{
		hSize[toDelete] = -1;
    	}

}


int main() 
{

	int index;
	int hSize[13];
	int number;

	
	for(int i = 0; i < 13 ; i++)
	{
		hSize[i] = -1;
	}
	
	cin >> number;

	
	while(number != -1) 
	{
		HashInsert(hSize, number);
		cin >> number;
	}
	
	
	for(int i = 0; i < 13; i++)
	{
        	if(hSize[i] == -1)
		{
			cout << endl;
	 	}
        	else
	    	{
			cout << hSize[i] << endl;
	    	}
	}

	cin >> number;

	
	while(number != -2)
	{
		index = HashSearch(hSize, number);
	   	if(index == -1)
       		{
            		cout<< "NOT_FOUND" << endl;
	   	}	
	   	else
	   	{
	        	cout << index << endl;
	   	}
	   	cin >> number;
    	}

	cin >> number;
	
	
	while(number != -3) 
	{
		HashDelete(hSize, number);
		cin >> number;
	}
	
	
	for (int i = 0; i < 13; i++) 
	{
		if(hSize[i] == -1)
		{
		    cout << endl;
		}
		else
		{
		    cout << hSize[i] << endl;
		}
	}
	
	return 0;
}
