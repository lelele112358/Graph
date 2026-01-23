/* ****
*   File: Graph_Connectivity.cpp
*   Description: Implements connectivity checking using BFS traversal.
**** */

#include "Graph_Connectivity.h"
#include <vector>
#include <queue>

using namespace std;

bool isConnected(const IGraph& graph) {
    int V = graph.getVertexCount();

    // Convention: empty graph is connected
    if (V == 0) return true;

    vector<bool> visited(V, false);
    queue<int> q;

    // Start BFS from vertex 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph.getNeighbors(u)) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Check if all vertices were visited
    for (bool v : visited) {
        if (!v)
            return false;
    }

    return true;
}
