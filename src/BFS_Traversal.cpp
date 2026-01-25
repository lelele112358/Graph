//***************************************************************
// File: BFS_Traversal.cpp
// Description:
//   Implements Breadth-First Search (BFS) traversal for any graph
//   that conforms to the IGraph interface.
//
//   The algorithm explores vertices level by level using a queue.
//   Each vertex is visited at most once, ensuring linear time
//   complexity relative to vertices and edges.
//
// Notes:
//   - Designed for small to medium-sized graphs
//   - Works with both adjacency list and adjacency matrix graphs
//***************************************************************

#include "BFS_Traversal.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function: BFS
// Parameters:
// const IGraph& graph - reference to any object implementing IGraph
// int start - starting vertex for traversal
// Output:
// Prints the BFS traversal order to standard output
// Notes:
// - Does nothing if start is out of bounds
void BFS(const IGraph& graph, int start) {
    int V = graph.getVertexCount();
    if (V == 0) return;

    if (start < 0 || start >= V) return;

    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue; // safety guard
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << endl;
}
