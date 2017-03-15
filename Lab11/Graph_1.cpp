
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <map>
#include <utility>
using namespace std;

struct dijkstra
{
bool visit;
string prev;
int cost;
dijkstra()
{
visit = false;
prev = "";
cost = INT_MAX;
}
};
struct Graph {
list<string> vertices;
map<pair<string,string>,int> edges;
void PrintOut(void);
void AddEdge(string,string,int);
bool FindVertex(string);
int FindEdgeCost(string vert1, string vert2);
int IsReachable(string vert1, string vert2);
void dijkstraAlgo(string vert1,string vert2);
};
void Graph::PrintOut(void) {
list<string>::iterator it;
map<pair<string,string>,int>::iterator eit;
for(it=vertices.begin(); it!=vertices.end(); it++) {
cout << *it << endl;
}
for(eit = edges.begin(); eit != edges.end(); eit++) {
cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
}
}
void Graph::AddEdge(string vert1,string vert2,int weight) {
edges[make_pair(vert1,vert2)] = weight;
}
bool Graph::FindVertex(string vert1) {
list<string>::iterator it;
for (it=vertices.begin(); it!=vertices.end();it++)
if(vert1 == *it)
return true;
return false;
}
int Graph::FindEdgeCost(string vert1, string vert2){
map<pair<string,string>,int>::iterator eit;
for (eit = edges.begin(); eit != edges.end(); eit++)
if ((*eit).first.first == vert1 && (*eit).first.second == vert2)
return (*eit).second;
return -1;
}
int Graph::IsReachable(string vert1, string vert2) {
map<string, string> color;
map<string, int> distance;
map<string, string> pi;
queue<string> Q;
list<string>::iterator it1;
for(it1=vertices.begin();it1!=vertices.end();it1++)
{
color[*it1] = "WHITE";
distance[*it1] = INT_MAX;
pi[*it1] = "NIL";
}
color[vert1] = "GRAY";
distance[vert1] = 0;
pi[vert1] = "NIL";
Q.empty();
Q.push(vert1);
map<pair<string,string>,int>::iterator eit;
while(!(Q.empty())){
string u = Q.front();
Q.pop();
for(eit=edges.begin(); eit!=edges.end(); eit++)
{
string adj;
if ((*eit).first.first == u){
adj = (*eit).first.second;
if (color[adj] == "WHITE"){
color[adj] = "GRAY";
distance[adj] = distance[u] + 1;
pi[adj] = pi[u];
Q.push(adj);
}
}
}
color[u] = "BLACK";
}
if (distance[vert2] != INT_MAX)
return distance[vert2];
return -1;
}
void Graph::dijkstraAlgo(string vert1,string vert2)
{
if(FindVertex(vert1)!=1 || FindVertex(vert2)!=1)
cout << "ERROR" << endl;
else
{
map<string,dijkstra> data;
for(list<string>::iterator it=vertices.begin(); it!=vertices.end(); it++)
data[*it] = dijkstra();
map <int, string> q;
map <int, string>::iterator qit;
map<pair<string, string>, int>::iterator dit;
string u;
data[vert1].cost = 0;
q[0] = vert1;
while(!q.empty())
{
qit = q.lower_bound(0);
u = (*qit).second;
q.erase(qit);
data[u].visit=true;
for(dit= edges.begin(); dit != edges.end(); dit++)
{
string adj;
if((*dit).first.first == u)
{
adj=(*dit).first.second;
if(data[adj].cost > (data[u].cost+(*dit).second))
{
data[adj].cost = data[u].cost + (*dit).second;
data[adj].prev = u;
q[data[adj].cost] = adj;
}
}
}
}
if(data[vert2].cost == INT_MAX)
cout << "INFINITY" << endl;
else	
cout << data[vert2].cost << endl;
}
}

int main(){
Graph G1;
vector<string> vertices;
string input = " ";
string input2 = " ";
int input3 = 0;
while (input != "END"){
cin >> input;
if (input == "END")
break;
G1.vertices.push_back(input);
}
input = " ";
while (input != "END"){
cin >> input;
if (input == "END")
break;
else{
cin >> input2;
cin >> input3;
}
if (G1.FindVertex(input) && G1.FindVertex(input2))
G1.AddEdge(input,input2,input3);
}
input = " ";
while (input !="END"){
cin >> input;
if (input == "END")
break;
else
cin >> input2;
G1.dijkstraAlgo(input,input2);
}
}
