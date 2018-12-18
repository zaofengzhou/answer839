//
// Created by zfzhou on 12/14/2018.
//
#include<bits/stdc++.h>
using namespace std;

#include "graph.h"

/*
// A utility function to add an edge in an undirect graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
    for(int v = 0; v < V; v++) {
        cout << "\n Adjacency list of vertx "
            << v << "\n head ";
        for(auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}
*/

class Graph
{
    int V;

    // Pointer to an array containing adjacency lists
    list<int> *adj;

    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);   //constructor

    // function to add an edge to grap
    void addEdge(int v, int w);

    // DFS traversal of the vertices reachable from v
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);    // Add w to v's list
}

void Graph::DFSUtil(int v, bool visited[]) {
    // Mark the current node as visitesd
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visted
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}

// Driver code
/*
int main()
{
//    int V = 5;
//    vector<int> adj[V];
//    addEdge(adj, 0, 1);
//    addEdge(adj, 0, 4);
//    addEdge(adj, 1, 2);
//    addEdge(adj, 1, 3);
//    addEdge(adj, 1, 4);
//    addEdge(adj, 2, 3);
//    addEdge(adj, 3, 4);
//
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}
*/
