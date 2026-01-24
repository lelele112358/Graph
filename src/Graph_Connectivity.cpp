//***************************************************************
// File: Graph_Connectivity.cpp
// Description:
//   Implements connectivity check using BFS traversal.
//   Determines if all vertices are reachable from vertex 0.
//
// Notes:
//   - Empty graph is considered connected
//***************************************************************

#include "Graph_Connectivity.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool isConnected(const IGraph& graph) {
    int V = graph.getVertexCount();
    if (V == 0) return true;

    vector<bool> visited(V, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph.getNeighbors(u)) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}
