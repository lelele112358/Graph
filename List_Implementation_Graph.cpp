#include "List_Implementation_Graph.h"
#include <iostream>

using namespace std;

GraphList::GraphList(int vertices)
    : V(vertices), adjList(vertices) {}

void GraphList::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void GraphList::display() const {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " -> ";
        }
        cout << "NULL\n";
    }
}
