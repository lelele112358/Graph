//***************************************************************
// File: Cycle_Detection.cpp
// Description:
//   Implements cycle detection for directed and undirected graphs
//   using DFS traversal.
//***************************************************************

#include "Cycle_Detection.h"
#include <vector>
using namespace std;

bool dfsUndirected(const IGraph& graph, int u, int parent, vector<bool>& visited) {
    visited[u] = true;
    for (int v : graph.getNeighbors(u)) {
        if (!visited[v]) {
            if (dfsUndirected(graph, v, u, visited)) return true;
        } else if (v != parent) return true;
    }
    return false;
}

bool dfsDirected(const IGraph& graph, int u, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;
    for (int v : graph.getNeighbors(u)) {
        if (!visited[v]) {
            if (dfsDirected(graph, v, visited, recStack)) return true;
        } else if (recStack[v]) return true;
    }
    recStack[u] = false;
    return false;
}

bool hasCycle(const IGraph& graph) {
    int V = graph.getVertexCount();
    vector<bool> visited(V, false);

    if (graph.isDirected()) {
        vector<bool> recStack(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsDirected(graph, i, visited, recStack)) return true;
            }
        }
    } else {
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsUndirected(graph, i, -1, visited)) return true;
            }
        }
    }
    return false;
}
