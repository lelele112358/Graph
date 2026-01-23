/* ****
*   File: List_Implementation_Graph.cpp
*   Description: Implements a graph using adjacency lists. Provides core
*                operations such as adding edges, displaying the graph,
*                and retrieving neighbors.
**** */

#include "List_Implementation_Graph.h"
#include <iostream>

using namespace std;

/* ---------- Helper Functions ---------- */
// Check if vertex index is valid
bool ListGraph::isValidVertex(int v) const {
    return v >= 0 && v < V;
}

// Check if edge u -> v already exists
bool ListGraph::edgeExists(int u, int v) const {
    for (int x : adj[u]) {
        if (x == v)
            return true;
    }
    return false;
}

/* ---------- Constructor ---------- */
// Initialize graph with given number of vertices and direction
ListGraph::ListGraph(int vertices, bool isDirected)
    : V(vertices), directed(isDirected), adj(vertices) {}

/* ---------- Core Operations ---------- */
// Add an edge u -> v
bool ListGraph::addEdge(int u, int v) {
    if (!isValidVertex(u) || !isValidVertex(v)) {
        cout << "Vertex out of range" << endl;
        return false;
    }

    if (edgeExists(u, v)) {
        cout << "Edge already exists" << endl;
        return false;
    }

    adj[u].push_back(v);

    // If undirected, also add edge v -> u
    if (!directed && u != v) {
        adj[v].push_back(u);
    }

    return true;
}

/* ---------- Display Graph ---------- */
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

/* ---------- Accessors ---------- */
int ListGraph::getVertexCount() const {
    return V;
}

bool ListGraph::isDirected() const {
    return directed;
}

vector<int> ListGraph::getNeighbors(int u) const {
    if (!isValidVertex(u))
        return {};
    return adj[u];
}
