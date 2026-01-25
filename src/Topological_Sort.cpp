//***************************************************************
// File: Topological_Sort.cpp
// Description:
//   Implements topological sorting using Kahn's algorithm.
//
// Algorithm overview:
//   1. Compute in-degree for every vertex
//   2. Push all vertices with in-degree 0 into a queue
//   3. Repeatedly remove a vertex from the queue, append it to
//      the ordering, and reduce in-degree of its neighbors
//   4. If all vertices are processed, a topological order exists
//      Otherwise, the graph contains a cycle
//
// Notes:
//   - Time Complexity: O(V + E)
//   - Space Complexity: O(V)
//***************************************************************

#include "Topological_Sort.h"
#include <queue>
using namespace std;

// Function: topologicalSort
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// vector<int>& order - output topological order
// Output:
// Returns true if a valid topological order exists, false otherwise
bool topologicalSort(const IGraph& graph, vector<int>& order) {
    int V = graph.getVertexCount();
    order.clear();

    // Topological sort is defined only for directed graphs
    if (!graph.isDirected()) return false;

    vector<int> indegree(V, 0);

    // Compute in-degree of each vertex
    for (int u = 0; u < V; u++) {
        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue;
            indegree[v]++;
        }
    }

    queue<int> q;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Process vertices
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue;

            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If not all vertices were processed, a cycle exists
    return ((int)order.size() == V);
}
