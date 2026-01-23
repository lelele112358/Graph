/* ****
*   File: DFS_Traversal.cpp
*   Description: Implements Depth-First Search (DFS) traversal using recursion.
*                Visits all vertices reachable from the start vertex in a depth-first manner.
**** */

#include "DFS_Traversal.h"
#include <iostream>
#include <vector>

using namespace std;

// Helper recursive function for DFS
void DFS_Helper(const IGraph& graph, int u, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " "; // process current vertex

    // Visit all unvisited neighbors recursively
    for (int v : graph.getNeighbors(u)) {
        if (!visited[v]) {
            DFS_Helper(graph, v, visited);
        }
    }
}

// Public DFS function
void DFS(const IGraph& graph, int start) {
    int V = graph.getVertexCount();
    if (V == 0) return; // empty graph

    vector<bool> visited(V, false);

    cout << "DFS Traversal starting from vertex " << start << ": ";
    DFS_Helper(graph, start, visited);
    cout << endl;
}
