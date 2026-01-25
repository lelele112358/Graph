//***************************************************************
// File: DFS_Traversal.cpp
// Description:
//   Implements Depth-First Search (DFS) traversal for any graph
//   that conforms to the IGraph interface.
//
// Notes:
//   - Uses recursion (may not be ideal for extremely deep graphs)
//***************************************************************

#include "DFS_Traversal.h"
#include <iostream>
#include <vector>
using namespace std;

// Function: DFS_Helper
// Parameters:
// const IGraph& graph - graph reference
// int u - current vertex
// vector<bool>& visited - visited tracking array
// Output:
// Prints DFS order as recursion explores neighbors
static void DFS_Helper(const IGraph& graph, int u, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : graph.getNeighbors(u)) {
        if (v < 0 || v >= (int)visited.size()) continue;
        if (!visited[v]) DFS_Helper(graph, v, visited);
    }
}

// Function: DFS
// Parameters:
// const IGraph& graph - reference to any object implementing IGraph
// int start - starting vertex
// Output:
// Prints DFS traversal order to standard output
// Notes:
// - Does nothing if start is out of bounds
void DFS(const IGraph& graph, int start) {
    int V = graph.getVertexCount();
    if (V == 0) return;

    if (start < 0 || start >= V) return;

    vector<bool> visited(V, false);

    cout << "DFS Traversal starting from vertex " << start << ": ";
    DFS_Helper(graph, start, visited);
    cout << endl;
}
