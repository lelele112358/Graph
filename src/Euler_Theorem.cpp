//***************************************************************
// File: Euler_Theorem.cpp
// Description:
//   Implements Euler path and Euler circuit existence checks
//   for both undirected and directed graphs.
//
// Euler Conditions:
//
//   Undirected graphs:
//     - All non-isolated vertices must be connected
//     - 0 odd-degree vertices  -> Euler circuit exists
//     - 2 odd-degree vertices  -> Euler path exists
//
//   Directed graphs:
//     - Euler circuit:
//         * inDegree(v) == outDegree(v) for all vertices
//         * all non-isolated vertices are strongly connected
//     - Euler path:
//         * exactly one vertex with (out - in) = 1  (start)
//         * exactly one vertex with (in - out) = 1  (end)
//         * all non-isolated vertices are strongly connected
//           after adding a virtual edge end -> start
//
// Notes:
//   - Designed for correctness and clarity
//   - Suitable for small to medium-sized graphs
//***************************************************************

#include "Euler_Theorem.h"
#include <vector>
#include <queue>
using namespace std;

// Function: buildReverseAdj
// Parameters:
// const IGraph& graph - reference to a directed graph
// vector<vector<int>>& rev - output reverse adjacency list
// Output:
// Builds rev[v] = all vertices u such that u -> v exists
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

// Function: firstNonIsolatedVertex
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Returns index of a vertex with degree > 0, or -1 if none exist
static int firstNonIsolatedVertex(const IGraph& graph) {
    int V = graph.getVertexCount();
    for (int i = 0; i < V; i++) {
        if (graph.getOutDegree(i) + graph.getInDegree(i) > 0) {
            return i;
        }
    }
    return -1;
}

// Function: nonIsolatedConnectedUndirected
// Parameters:
// const IGraph& graph - reference to an undirected graph
// Output:
// Returns true if all non-isolated vertices are connected
static bool nonIsolatedConnectedUndirected(const IGraph& graph) {
    int V = graph.getVertexCount();
    int start = firstNonIsolatedVertex(graph);

    // No edges at all -> trivially Euler
    if (start == -1) return true;

    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if ((graph.getOutDegree(i) + graph.getInDegree(i) > 0) && !visited[i]) {
            return false;
        }
    }
    return true;
}

// Function: dfsDirectedWithOptionalExtraEdge
// Parameters:
// const vector<vector<int>>& adj - adjacency list
// int u - current vertex
// vector<bool>& visited - visited flags
// int extraFrom - virtual edge source (-1 if none)
// int extraTo - virtual edge destination
// Output:
// Marks all reachable vertices in visited
static void dfsDirectedWithOptionalExtraEdge(const vector<vector<int>>& adj,
                                            int u,
                                            vector<bool>& visited,
                                            int extraFrom,
                                            int extraTo) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (v < 0 || v >= (int)visited.size()) continue;
        if (!visited[v]) {
            dfsDirectedWithOptionalExtraEdge(adj, v, visited, extraFrom, extraTo);
        }
    }

    // Optional virtual edge (used for Euler path connectivity)
    if (u == extraFrom && extraTo >= 0 && extraTo < (int)visited.size()) {
        if (!visited[extraTo]) {
            dfsDirectedWithOptionalExtraEdge(adj, extraTo, visited, extraFrom, extraTo);
        }
    }
}

// Function: stronglyConnectedOnNonIsolated
// Parameters:
// const IGraph& graph - reference to a directed graph
// int extraFrom - virtual edge source (-1 if none)
// int extraTo - virtual edge destination
// Output:
// Returns true if all non-isolated vertices belong to one SCC
static bool stronglyConnectedOnNonIsolated(const IGraph& graph,
                                          int extraFrom,
                                          int extraTo) {
    int V = graph.getVertexCount();
    int start = firstNonIsolatedVertex(graph);

    if (start == -1) return true;

    vector<vector<int>> adj(V);
    for (int u = 0; u < V; u++) {
        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue;
            adj[u].push_back(v);
        }
    }

    vector<vector<int>> rev;
    buildReverseAdj(graph, rev);

    vector<bool> visited1(V, false);
    dfsDirectedWithOptionalExtraEdge(adj, start, visited1, extraFrom, extraTo);

    vector<bool> visited2(V, false);
    int revExtraFrom = (extraTo >= 0 ? extraTo : -1);
    int revExtraTo   = (extraFrom >= 0 ? extraFrom : -1);

    dfsDirectedWithOptionalExtraEdge(rev, start, visited2, revExtraFrom, revExtraTo);

    for (int i = 0; i < V; i++) {
        if (graph.getOutDegree(i) + graph.getInDegree(i) == 0) continue;
        if (!visited1[i] || !visited2[i]) return false;
    }
    return true;
}

// Function: hasEulerPathOrCircuit
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns true if an Euler path or Euler circuit exists
bool hasEulerPathOrCircuit(const IGraph& graph) {
    int V = graph.getVertexCount();
    if (V == 0) return true;

    // ---------------- Undirected graph ----------------
    if (!graph.isDirected()) {
        if (!nonIsolatedConnectedUndirected(graph)) return false;

        int oddCount = 0;
        for (int i = 0; i < V; i++) {
            if (graph.getOutDegree(i) % 2 != 0) oddCount++;
        }

        return (oddCount == 0 || oddCount == 2);
    }

    // ---------------- Directed graph ----------------
    int startCandidates = 0;
    int endCandidates = 0;
    int startVertex = -1;
    int endVertex = -1;

    for (int i = 0; i < V; i++) {
        int out = graph.getOutDegree(i);
        int in  = graph.getInDegree(i);

        if (out - in == 1) {
            startCandidates++;
            startVertex = i;
        } else if (in - out == 1) {
            endCandidates++;
            endVertex = i;
        } else if (in != out) {
            return false;
        }
    }

    bool isCircuitCase = (startCandidates == 0 && endCandidates == 0);
    bool isPathCase    = (startCandidates == 1 && endCandidates == 1);

    if (!isCircuitCase && !isPathCase) return false;

    if (isCircuitCase) {
        return stronglyConnectedOnNonIsolated(graph, -1, -1);
    }

    // Path case: add virtual edge end -> start
    return stronglyConnectedOnNonIsolated(graph, endVertex, startVertex);
}
