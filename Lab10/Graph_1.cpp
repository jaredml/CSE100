#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using nspace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string v1, string v2);
    int IsReachable(string v1, string v2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator edgeit;
    
    for(it = vertices.begin(); it != vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(edgeit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*edgeit).first.first << " " << (*edgeit).first.second << " " << (*edgeit).second << endl;
    }
}
//Add the Edges
void Graph::AddEdge(string v1,string v2,int weight) {

    //If Both True, Make a Pair
    if(FindVertex(v1) && FindVertex(v2)) {

	//insert pair into map
        edges.insert(make_pair(make_pair(v1,v2), weight));
    }
}

//Find vertex, bool
bool Graph::FindVertex(string v1) {
    list<string>::iterator it;

     //iterate through the list of vertices
    for(it = vertices.begin(); it != vertices.end(); it++) {

	//if Found, return true
        if(*it == v1) {
            return true;
        }
    }
    // else return false
    return false;
}

int main() {

    
    Graph G;
    
    
    string n;
    cin >> n;

   
    while(n != "END") {
        G.vertices.push_back(n);
        
	
        cin >> n;
    }
    
    string first, second;
    int weight;
  
    cin >> first;
     
    //ADD Edge  
    //while not END
    while(first != "END") {
	
        cin >> second;

        cin >> weight;


        G.AddEdge(first, second, weight);//start insertion
        
	//repeat
        cin >> first;   //start next insertion
    }
    
    //Print Out the map
    G.PrintOut();
}
