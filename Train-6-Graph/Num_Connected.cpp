#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph{
  ll V;
  list<ll> *adj;
  int numConnected;
  void DFS(ll v, bool visited[]);
public:
  Graph(ll V); //constructor
  ~Graph();
  void addEdge(ll v, ll w);
  void connectedComponents();
  int getNumConnected();
};

void Graph::connectedComponents(){
  bool *visited = new bool[V];
  for(ll v = 1; v <= V; v++) visited[v] = false;

  for(ll v = 1; v <= V; v++){
    if(!visited[v]){
      DFS(v, visited);
      numConnected ++;
    }
  }
  delete[] visited;
}
void Graph::DFS(ll v, bool visited[]){
  visited[v] = true;
  // cout << v << " ";
  for(list<ll>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
    if(!visited[*i])
      DFS(*i, visited);
}
int Graph::getNumConnected(){
  return this->numConnected;
}
Graph::Graph(ll V){
  this->V = V;
  adj = new list<ll>[V+1];
  this->numConnected = 0;
}
Graph::~Graph(){
  delete[] adj;
}
void Graph::addEdge(ll v, ll w){
  adj[v].push_back(w);
  adj[w].push_back(v);
}

int main(){
    ll N, M; cin >> N >> M;
    Graph g(N); 
    for(ll i = 0; i < M; i++){
      ll u, v; cin >> u >> v;
      g.addEdge(u,v);
    }
    g.connectedComponents(); 
    cout << g.getNumConnected();
  
    return 0; 
}