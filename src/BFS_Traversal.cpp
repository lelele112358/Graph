/* ****
*   File: BFS_Traversal.cpp
*   Description: Implements Breadth-First Search (BFS) traversal using a queue.
*                Visits all vertices reachable from the start vertex level by level.
**** */

#include "BFS_Traversal.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(const IGraph& graph, int start) {
    int V = graph.getVertexCount();
    if (V == 0) return; // empty graph

    vector<bool> visited(V, false); // track visited vertices
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " "; // process current vertex

        // Visit all neighbors
        for (int v : graph.getNeighbors(u)) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}
