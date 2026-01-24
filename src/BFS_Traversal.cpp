//***************************************************************
// File: BFS_Traversal.cpp
// Description:
//   Implements Breadth-First Search (BFS) traversal using a queue.
//   Visits all vertices reachable from start vertex level by level.
//
// Notes:
//   - Prints traversal to console
//***************************************************************

#include "BFS_Traversal.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(const IGraph& graph, int start) {
    int V = graph.getVertexCount();
    if (V == 0) return;

    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : graph.getNeighbors(u)) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}
