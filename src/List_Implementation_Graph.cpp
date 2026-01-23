/*
 * List_Implementation_Graph.cpp
 *
 * Description:
 *  This file implements the ListGraph class, which represents a graph using
 *  an adjacency list. It provides functionality to add edges, check for edge
 *  existence, validate vertices, and display the graph.
 *
 *  Key features:
 *  - Constructor: Initializes an adjacency array for the given number of vertices.
 *  - Destructor: Cleans up all dynamically allocated nodes in the adjacency lists.
 *  - addEdge(): Adds edges for directed or undirected graphs, while preventing
 *    duplicates and self-loops for undirected graphs.
 *  - display(): Prints the adjacency list representation of the graph.
 */
#include "List_Implementation_Graph.h"
#include <iostream>
using namespace std;

#define endln endl

ListGraph::ListGraph(int vertices, bool isDirected)
    : V(vertices), directed(isDirected) {

    adj = new Node*[V];
    for (int i = 0; i < V; i++) {
        adj[i] = nullptr;
    }
}

ListGraph::~ListGraph() {
    for (int i = 0; i < V; i++) {
        Node* curr = adj[i];
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    delete[] adj;
}

bool ListGraph::isValidVertex(int v) const {
    return v >= 0 && v < V;
}

bool ListGraph::edgeExists(int u, int v) const {
    for (Node* curr = adj[u]; curr; curr = curr->next) {
        if (curr->vertex == v)
            return true;
    }
    return false;
}

bool ListGraph::addEdge(int u, int v) {
    if (!isValidVertex(u) || !isValidVertex(v)) {
        cout << "Vertex out of range." << endln;
        return false;
    }

    if (directed) {
        if (edgeExists(u, v)) {
            cout << "Edge already exists." << endln;
            return false;
        }
        adj[u] = new Node{v, adj[u]};
        return true;
    } else {
        if (u == v) {
            cout << "No self-loops in undirected graph." << endln;
            return false;
        }
        if (edgeExists(u, v)) {
            cout << "Edge already exists." << endln;
            return false;
        }
        adj[u] = new Node{v, adj[u]};
        adj[v] = new Node{u, adj[v]};
        return true;
    }
}

void ListGraph::display() const {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (Node* curr = adj[i]; curr; curr = curr->next) {
            cout << curr->vertex << " -> ";
        }
        cout << "NULL" << endln;
    }
}

