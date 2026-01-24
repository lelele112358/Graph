//***************************************************************
// File: List_Implementation_Graph.cpp
// Description:
//   Implements a graph using adjacency lists. Provides core
//   operations such as adding edges, displaying the graph,
//   and retrieving neighbors.
//
// Notes:
//   - Efficient for sparse graphs
//   - Handles directed and undirected graphs
//***************************************************************

#include "List_Implementation_Graph.h"
using namespace std;

/* ---------- Helper Functions ---------- */
bool ListGraph::isValidVertex(int v) const {
    return v >= 0 && v < V;
}

bool ListGraph::edgeExists(int u, int v) const {
    for (int x : adj[u]) {
        if (x == v) return true;
    }
    return false;
}

/* ---------- Constructor ---------- */
ListGraph::ListGraph(int vertices, bool isDirected)
    : V(vertices), directed(isDirected), adj(vertices) {}

/* ---------- Core Operations ---------- */
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

    if (!directed && u != v) {
        adj[v].push_back(u);
    }

    return true;
}

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
int ListGraph::getVertexCount() const { return V; }
bool ListGraph::isDirected() const { return directed; }

vector<int> ListGraph::getNeighbors(int u) const {
    if (!isValidVertex(u)) return {};
    return adj[u];
}
