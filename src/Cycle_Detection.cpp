//***************************************************************
// File: Cycle_Detection.cpp
// Description:
//   Implements cycle detection for both directed and undirected
//   graphs using DFS.
//
// Notes:
//   - Undirected graphs: a back-edge to a visited node that is not
//     the parent indicates a cycle.
//   - Directed graphs: a node reached that is already in the
//     recursion stack indicates a cycle.
//***************************************************************

#include "Cycle_Detection.h"
#include <vector>
using namespace std;

// Function: dfsUndirected
// Parameters:
// const IGraph& graph - graph reference
// int u - current node
// int parent - parent node in DFS tree
// vector<bool>& visited - visited flags
// Output:
// Returns true if cycle found, false otherwise
static bool dfsUndirected(const IGraph& graph, int u, int parent, vector<bool>& visited) {
    int V = graph.getVertexCount();
    visited[u] = true;

    for (int v : graph.getNeighbors(u)) {
        if (v < 0 || v >= V) continue;

        if (!visited[v]) {
            if (dfsUndirected(graph, v, u, visited)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

// Function: dfsDirected
// Parameters:
// const IGraph& graph - graph reference
// int u - current node
// vector<bool>& visited - visited flags
// vector<bool>& inStack - recursion stack flags
// Output:
// Returns true if cycle found, false otherwise
static bool dfsDirected(const IGraph& graph, int u, vector<bool>& visited, vector<bool>& inStack) {
    int V = graph.getVertexCount();
    visited[u] = true;
    inStack[u] = true;

    for (int v : graph.getNeighbors(u)) {
        if (v < 0 || v >= V) continue;

        if (!visited[v]) {
            if (dfsDirected(graph, v, visited, inStack)) return true;
        } else if (inStack[v]) {
            return true;
        }
    }

    inStack[u] = false;
    return false;
}

// Function: hasCycle
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Returns true if graph contains a cycle
bool hasCycle(const IGraph& graph) {
    int V = graph.getVertexCount();
    if (V == 0) return false;

    vector<bool> visited(V, false);

    if (graph.isDirected()) {
        vector<bool> inStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsDirected(graph, i, visited, inStack)) return true;
            }
        }
        return false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsUndirected(graph, i, -1, visited)) return true;
        }
    }
    return false;
}
