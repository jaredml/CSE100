//HashSort
#include <iostream>
#include <list>
using namespace std;

void HashInsert(list<int> T[], int k, int a_size);
void HashSearch(list<int> T[], int k, int a_size);
void HashDelete(list<int> T[], int k, int a_size);

int main() {
	//declaration
	int a_size;
	int key;

	cin >> a_size;
	
	//list decl
	list<int> *T = new list<int>[a_size];
	list<int>::iterator iter;

	cin >> key;

	while(key != -1){
		HashInsert(T, key, a_size);
		cin >> key;	
	}
		//iterate through hash
		for(int i = 0; i < a_size; i++)
		{
			iter = T[i].begin();
			while(iter != T[i].end()){
				cout << *iter << "->";
				iter++;
			}
			cout << endl;
		}
	cin >> key;

	//take integers from input untill -2 is reached
	while(key != -2){
		HashSearch(T, key, a_size);
		cin >> key;
	}
	cin >> key;

	//read integers from input and delete it until -3 is reached
	while(key != -3){
		HashDelete(T, key, a_size);
		cin >> key;
	}

	for(int j = 0; j < a_size; j++){
		iter = T[j].begin();
		while(iter != T[j].end()){
			cout << *iter << "->";
			iter++;
		}
		cout << endl;
	}
}

//Hash Insert
void HashInsert(list<int> T[], int k, int a_size){
	int h= k % a_size; // k mod a_size
	T[h].push_front(k); //push from front
}

void HashSearch(list<int> T[], int k, int a_size){
	int listIndex = 0;
	list<int>::iterator iter;
	//go to index; % is modulo
	int hashIndex = k % a_size;
	
	//declare and set f to false 
	bool f = false;
	
	if(T[hashIndex].empty()){
		cout << "NOT_FOUND" << endl;
		f = true;	
	}
	else{
		iter = T[hashIndex].begin();
		while(iter != T[hashIndex].end()){
			if(*iter == k){
				cout << hashIndex << "," << listIndex << endl;
				f = true;			
			}
			iter++;
			listIndex++;	
		}
	}
	//if not false
	if(!f){
		cout << "NOT_FOUND" << endl;	
	}
}

//Delete Hash; clear
void HashDelete(list<int> T[], int k, int a_size){
	int i = k % a_size;
	T[i].remove(k);
}
