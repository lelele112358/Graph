//***************************************************************
// File: List_Implementation_Graph.cpp
// Description:
//   Implements an adjacency list graph that conforms to the IGraph interface.
//   Provides edge insertion, display, neighbor queries, and degree calculations.
//
// Notes:
//   - Memory efficient for sparse graphs
//   - Display mimics linked-list style output using arrows (->)
//***************************************************************

#include "List_Implementation_Graph.h"

// Function: isValidVertex
// Parameters:
// int v - vertex index
// Output:
// Returns true if v is within [0, V-1], otherwise false
bool ListGraph::isValidVertex(int v) const {
    return v >= 0 && v < V;
}

// Function: ListGraph (Constructor)
// Parameters:
// int vertices - number of vertices
// bool isDirected - true if graph is directed, false if undirected
// Output:
// Builds an empty adjacency list graph
ListGraph::ListGraph(int vertices, bool isDirected)
    : V(vertices), directed(isDirected), adj(vertices) {}

// Function: addEdge
// Parameters:
// int u - source vertex
// int v - destination vertex
// Output:
// Returns true if edge is added successfully, false if invalid vertices
// Notes:
// - Undirected graphs store both (u,v) and (v,u)
bool ListGraph::addEdge(int u, int v) {
    if (!isValidVertex(u) || !isValidVertex(v)) return false;

    adj[u].push_back(v);

    if (!directed && u != v) {
        adj[v].push_back(u);
    }

    return true;
}

// Function: display
// Parameters:
// None
// Output:
// Prints adjacency list in linked-list style:
//   u: v1 -> v2 -> ... -> NULL
// Notes:
// - Output format is for readability only
void ListGraph::display() const {
    cout << "Adjacency List:" << endl;

    for (int i = 0; i < V; i++) {
        cout << i << ": ";

        for (int v : adj[i]) {
            cout << v << " -> ";
        }

        cout << "NULL" << endl;
    }
}

// Function: getVertexCount
// Parameters:
// None
// Output:
// Returns the number of vertices in the graph
int ListGraph::getVertexCount() const {
    return V;
}

// Function: isDirected
// Parameters:
// None
// Output:
// Returns true if graph is directed, false otherwise
bool ListGraph::isDirected() const {
    return directed;
}

// Function: getNeighbors
// Parameters:
// int u - vertex to query
// Output:
// Returns a vector of neighbors of u (empty if u is invalid)
vector<int> ListGraph::getNeighbors(int u) const {
    if (!isValidVertex(u)) return {};
    return adj[u];
}

// Function: getOutDegree
// Parameters:
// int v - vertex to query
// Output:
// Returns out-degree of v (0 if invalid)
// Notes:
// - For undirected graphs, this equals the degree of v
int ListGraph::getOutDegree(int v) const {
    if (!isValidVertex(v)) return 0;
    return (int)adj[v].size();
}

// Function: getInDegree
// Parameters:
// int v - vertex to query
// Output:
// Returns in-degree of v (0 if invalid)
// Notes:
// - Runs in O(V + E) time
int ListGraph::getInDegree(int v) const {
    if (!isValidVertex(v)) return 0;

    int count = 0;
    for (int u = 0; u < V; u++) {
        for (int x : adj[u]) {
            if (x == v) count++;
        }
    }
    return count;
}
