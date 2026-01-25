//***************************************************************
// File: Graph_Connectivity.cpp
// Description:
//   Implements connectivity checking using BFS.
//
// Notes:
//   - For undirected graphs, BFS uses getNeighbors directly.
//   - For directed graphs, we check weak connectivity by allowing
//     traversal along both outgoing and incoming edges.
//***************************************************************

#include "Graph_Connectivity.h"
#include <vector>
#include <queue>
using namespace std;

// Function: buildReverseAdj
// Parameters:
// const IGraph& graph - graph reference
// vector<vector<int>>& rev - output reverse adjacency list
// Output:
// Fills rev[v] with all u such that u -> v exists
static void buildReverseAdj(const IGraph& graph, vector<vector<int>>& rev) {
    int V = graph.getVertexCount();
    rev.assign(V, {});

    for (int u = 0; u < V; u++) {
        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue;
            rev[v].push_back(u);
        }
    }
}

// Function: isConnected
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Returns true if graph is connected (one component)
// Notes:
// - Directed graphs are treated as weakly connected here
bool isConnected(const IGraph& graph) {
    int V = graph.getVertexCount();
    if (V == 0) return true;

    vector<bool> visited(V, false);
    queue<int> q;

    // Build reverse adjacency only if needed
    vector<vector<int>> rev;
    if (graph.isDirected()) {
        buildReverseAdj(graph, rev);
    }

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Outgoing neighbors
        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }

        // Incoming neighbors (for weak connectivity in directed graphs)
        if (graph.isDirected()) {
            for (int v : rev[u]) {
                if (v < 0 || v >= V) continue;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    for (bool seen : visited) {
        if (!seen) return false;
    }
    return true;
}
