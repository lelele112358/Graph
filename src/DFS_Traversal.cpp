//***************************************************************
// File: DFS_Traversal.cpp
// Description:
//   Implements Depth-First Search (DFS) traversal using recursion.
//
// Notes:
//   - Prints traversal to console
//***************************************************************

#include "DFS_Traversal.h"
#include <vector>
#include <iostream>
using namespace std;

void DFS_Helper(const IGraph& graph, int u, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : graph.getNeighbors(u)) {
        if (!visited[v]) DFS_Helper(graph, v, visited);
    }
}

void DFS(const IGraph& graph, int start) {
    int V = graph.getVertexCount();
    if (V == 0) return;

    vector<bool> visited(V, false);
    cout << "DFS Traversal starting from vertex " << start << ": ";
    DFS_Helper(graph, start, visited);
    cout << endl;
}
