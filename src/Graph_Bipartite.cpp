//***************************************************************
// File: Graph_Bipartite.cpp
// Description:
//   Implements bipartite checking using BFS coloring.
//   Also provides helper functions to extract left/right partitions.
//
// Notes:
//   - A graph is bipartite if we can assign each vertex a color
//     (0 or 1) such that every edge connects opposite colors.
//   - Designed for small to medium graphs
//***************************************************************

#include "Graph_Bipartite.h"
#include <queue>
using namespace std;

// Function: buildBipartiteColoring
// Parameters:
// const IGraph& graph - graph reference
// vector<int>& color - output color array (size V), values in {-1,0,1}
// Output:
// Returns true if bipartite, false if conflict found
// Notes:
// - Uses BFS from each uncolored vertex (handles disconnected graphs)
static bool buildBipartiteColoring(const IGraph& graph, vector<int>& color) {
    int V = graph.getVertexCount();
    color.assign(V, -1);

    for (int start = 0; start < V; start++) {
        if (color[start] != -1) continue;

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph.getNeighbors(u)) {
                if (v < 0 || v >= V) continue; // safety guard

                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }

    return true;
}

// Function: isBipartite
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns true if graph is bipartite
bool isBipartite(const IGraph& graph) {
    vector<int> color;
    return buildBipartiteColoring(graph, color);
}

// Function: getLeftPartition
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Returns all vertices colored 0
vector<int> getLeftPartition(const IGraph& graph) {
    vector<int> color;
    if (!buildBipartiteColoring(graph, color)) return {};

    vector<int> left;
    for (int i = 0; i < (int)color.size(); i++) {
        if (color[i] == 0) left.push_back(i);
    }
    return left;
}

// Function: getRightPartition
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Returns all vertices colored 1
vector<int> getRightPartition(const IGraph& graph) {
    vector<int> color;
    if (!buildBipartiteColoring(graph, color)) return {};

    vector<int> right;
    for (int i = 0; i < (int)color.size(); i++) {
        if (color[i] == 1) right.push_back(i);
    }
    return right;
}
