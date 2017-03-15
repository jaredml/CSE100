/*
	Find the minimum number of operations required to multiply
	together a chain of matrices.
	Input:
		number of matrices and their sizes (rows, columns).
	Output:
		the minimum number of operations
		(multiply and add two numbers) plus if you can,
		the optimal ordering for the multiplications.
*/
#include <iostream>
#include <limits.h>
 
using namespace std;
 
/*void print_optimal_parenth(vector<vector<int>> v, int i, int j)
{
	if(i == j)
	{
		cout << (char)(65) << i;
	}
	else
	{
		cout << "(";
		print_optimal_parenth(sols,i,sols[i][j]);
		print_optimal_parenth(sols,sols[i][j]+1,j);
		cout << ")";
	}
}*/
 
void matrix_chain_order(int *p, int size)
{
	int n = size-1, i = 0, l, j = 0, k, q = 0;// q is the cost and multipications 
	int m[n][n]; //min number of multipications (cost) 
	int s[n][n]; 

	for(i=0; i < n; i++){
		m[i][i]=0;
	}

	for(l=2; l <= n;l++){  
		for(i=0; i <= n-l; i++){
			j = i+l-1;
			m[i][j]=INT_MAX;
			for(k=i; k < j; k++){
				q=m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				if(q < m[i][j]){
					m[i][j]=q; 
					s[i][j]=k; //Index that achived optimal cost
				}
			}
		}
	}

	cout << m[0][n-1] << endl;
		//return m and s 
}
 
/*void determine_mult(int total_matrices)
{
	int rows, cols;
	int * sequence = new int[total_matrices+1]; 
	cout << "Enter number of rows matrix 1" << endl;
	cin >> rows;
	while(rows<0)
	{
		cout << "\nPlease enter a positive value:" << endl;
		cin >> rows;
	}
	sequence[0] = rows;
	for(int i=0;i<total_matrices;i++)
	{
 
		cout << "Enter number of columns for matrix " << i+1 << endl;
		cin >> cols;
		while(cols<0)
		{
			cout << "\nPlease enter a positive value:" << endl;
			cin >> cols;
		}
		sequence[i+1] = cols;
	}

	cout << "Desired sequence:\n";
	cout << "(" << sequence[0] << ")";
	for(int i=1;i<total_matrices+1;i++)
	{
		cout << "(" << sequence[i] << ")";
		if(i<total_matrices)
			cout << "x(" << sequence[i] << ")";
	}
	cout << endl;
 
	//determine order of the chain multiplication
	matrix_chain_order(sequence,total_matrices);
 
	//free memory
	delete[] sequence;
}*/
int main()
{
	//cout << "********************Optimal Matrix Chain Multiplication********************\n\n";
	//cout << "This program determines the optimal parenthesization when multiplying a chain of matrices\n";
	int total_matrices;
	//cout << "How many matrices would you like to multiply?" << endl;
	cin >> total_matrices;
	//cout << "\n";
	while(total_matrices != 0)
	{
		
		//cout << "sorry, invalid value\nEnter a positive number: ";
		int p[total_matrices];
		for (int i = 0; i < (total_matrices+1); i++)
		{
			cin >> p[i];

		}
		//cout << "\n";
	
		matrix_chain_order(p, total_matrices + 1);
		cin >> total_matrices;
	}
	return 0;
}
