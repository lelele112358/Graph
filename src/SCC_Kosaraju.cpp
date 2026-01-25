//***************************************************************
// File: SCC_Kosaraju.cpp
// Description:
//   Implements Strongly Connected Components (SCC) detection using
//   Kosaraju's algorithm.
//
// Steps:
//   1) DFS on original graph to compute finish-time stack/order
//   2) Build reverse adjacency list
//   3) DFS on reversed graph using reverse finish order
//
// Complexity:
//   - Time:  O(V + E)
//   - Space: O(V + E)
//
// Notes:
//   - Uses the IGraph interface only
//   - Includes basic safety guards for invalid neighbors
//***************************************************************

#include "SCC_Kosaraju.h"

// Function: dfsFinishOrder
// Parameters:
// const IGraph& graph - graph reference
// int u - current vertex
// vector<bool>& visited - visited array
// vector<int>& order - output finish order (push after exploring neighbors)
// Output:
// Performs DFS and stores vertices by finishing time
static void dfsFinishOrder(const IGraph& graph,
                           int u,
                           vector<bool>& visited,
                           vector<int>& order) {
    visited[u] = true;

    int V = graph.getVertexCount();
    for (int v : graph.getNeighbors(u)) {
        if (v < 0 || v >= V) continue;
        if (!visited[v]) dfsFinishOrder(graph, v, visited, order);
    }

    // Push after exploring neighbors = "finish time" order
    order.push_back(u);
}

// Function: buildReverseAdj
// Parameters:
// const IGraph& graph - graph reference
// vector<vector<int>>& rev - output reverse adjacency list
// Output:
// Builds rev[v] = all u such that u -> v is an edge in the original graph
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

// Function: dfsCollectComponent
// Parameters:
// const vector<vector<int>>& rev - reversed adjacency list
// int u - current vertex
// vector<bool>& visited - visited array
// vector<int>& component - output vertices in this SCC
// Output:
// DFS on reversed graph to collect one SCC
static void dfsCollectComponent(const vector<vector<int>>& rev,
                                int u,
                                vector<bool>& visited,
                                vector<int>& component) {
    visited[u] = true;
    component.push_back(u);

    for (int v : rev[u]) {
        if (v < 0 || v >= (int)visited.size()) continue;
        if (!visited[v]) dfsCollectComponent(rev, v, visited, component);
    }
}

// Function: kosarajuSCC
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// vector<int>& componentId - output mapping from vertex to SCC index
// Output:
// Returns SCC list (each SCC is a vector of vertices)
vector<vector<int>> kosarajuSCC(const IGraph& graph, vector<int>& componentId) {
    int V = graph.getVertexCount();
    componentId.assign(V, -1);

    vector<vector<int>> sccs;
    if (V == 0) return sccs;

    // 1) DFS on original graph to compute finish order
    vector<bool> visited(V, false);
    vector<int> order;
    order.reserve(V);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfsFinishOrder(graph, i, visited, order);
    }

    // 2) Build reverse adjacency list
    vector<vector<int>> rev;
    buildReverseAdj(graph, rev);

    // 3) DFS on reversed graph in reverse finish order
    fill(visited.begin(), visited.end(), false);

    int sccIndex = 0;

    for (int idx = V - 1; idx >= 0; idx--) {
        int start = order[idx];
        if (start < 0 || start >= V) continue;

        if (!visited[start]) {
            vector<int> component;
            dfsCollectComponent(rev, start, visited, component);

            // Assign componentId for vertices in this SCC
            for (int v : component) {
                if (v >= 0 && v < V) componentId[v] = sccIndex;
            }

            sccs.push_back(component);
            sccIndex++;
        }
    }

    return sccs;
}
