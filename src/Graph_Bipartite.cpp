/* ****
*   File: Graph_Bipartite.cpp
*   Description: Implements a function to check if a given graph is bipartite.
**** */

#include "Graph_Bipartite.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function: isBipartite
// Description: Determines whether the given graph is bipartite.
// Parameters:
//    const IGraph& graph - The input graph interface
// Returns: true if the graph is bipartite, false otherwise
bool isBipartite(const IGraph& graph) {
    int V = graph.getVertexCount(); // Total number of vertices
    vector<int> color(V, -1);       // -1 = uncolored, 0 = color A, 1 = color B

    // Check each component of the graph
    for (int start = 0; start < V; start++) {
        if (color[start] != -1) continue; // Skip already colored vertices

        queue<int> q;
        q.push(start);
        color[start] = 0; // Assign initial color

        // BFS traversal
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();

            // Process all neighbors of u
            for (int v : graph.getNeighbors(u)) {
                if (color[v] == -1) {
                    // Assign opposite color to neighbor
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    // Found same-color adjacent vertices → not bipartite
                    return false;
                }
            }
        }
    }

    return true; // No conflicts found, graph is bipartite
}
