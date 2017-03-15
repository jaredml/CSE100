#include<iostream>
#include<stdlib.h>
using namespace std;

//template<class T>
int isort(int a[],int n, int i)
{

     if(i == 0){
	a[i] = n;
	return 1;}
     for(int k = 0;k < i; k++)
     {
             
		int temp;
		if(n <a[k]){
		temp = a[k];
		a[k] = n;
             for(int j = k+1;j <i+1 ; j++)
             {
			a[j]+=temp;
			temp=a[j]-temp;
			a[j] = a[j] -temp;
		   		   		
		}
	return 1;

	}
         a[i]=n;
return 1;   
     }
	
}


int main()
{
    int i,n,x;
    //cout << "Enter number of elements: ";
    
    
    //cerr << n;
    
    //cout << "Enter elements\n";
    while(true){
	cin >> n;
	if( n == 0)
		break;              
	int a[n]; 
	for(i = 0;i < n;i++)
                {
                    
                    cin >> x;
                   isort(a, x, i); 
		}
                
             
             //cout<<"After sorting the elements are\n";
             for(i = 0;i < n;i++)
             {
                    cout << a[i] << "\n";
                    }      
                      
    }            
    return 0;
}
