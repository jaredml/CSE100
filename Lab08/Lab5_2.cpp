//HashSort
#include <iostream>
#include <list>
using namespace std;

void HashInsert(list<int> T[], int k, int a_size);
void HashSearch(list<int> T[], int k, int a_size);
void HashDelete(list<int> T[], int k, int a_size);


//Hash Insert function
void HashInsert(list<int> T[], int k, int size){
	int h = k % size; // k mod size
	T[h].push_front(k); //push from front
}

void HashSearch(list<int> T[], int k, int size){
	int listIndex = 0;
	list<int>::iterator iterate;
	//go to index; % is modulo
	int hashIndex = k % size;
	
	 
	bool x = false;//declare and set x to false
	
	if(T[hashIndex].empty()){
		cout << "NOT_FOUND" << endl;
		x = true;	
	}
	else{
		iterate = T[hashIndex].begin();
		while(iterate != T[hashIndex].end()){
			if(*iterate == k){
				cout << hashIndex << "," << listIndex << endl;
				x = true;			
			}
			iterate++;
			listIndex++;	
		}
	}
	//if not false
	if(!x){
		cout << "NOT_FOUND" << endl;	
	}
}

//Delete Hash; clear
void HashDelete(list<int> T[], int k, int size){
	int i = k % size;
	T[i].remove(k);
}

int main() {
	//declaring variables
	int size;
	int key;

	cin >> size;
	
	//lists being declared
	list<int> *T = new list<int>[size];
	list<int>::iterator iterate;

	cin >> key;

	while(key != -1){
		HashInsert(T, key, size);
		cin >> key;	
	}
		//iterate through hash
		for(int i = 0; i < size; i++)
		{
			iterate = T[i].begin();
			while(iterate != T[i].end()){
				cout << *iterate << "->";
				iterate++;
			}
			cout << endl;
		}
	cin >> key;

	//take integers from input untill -2 is reached
	while(key != -2){
		HashSearch(T, key, size);
		cin >> key;
	}
	cin >> key;

	//read integers from input and delete it until -3 is reached
	while(key != -3){
		HashDelete(T, key, size);
		cin >> key;
	}

	for(int j = 0; j < size; j++){
		iterate = T[j].begin();
		while(iterate != T[j].end()){
			cout << *iterate << "->";
			iterate++;
		}
		cout << endl;
	}
}

