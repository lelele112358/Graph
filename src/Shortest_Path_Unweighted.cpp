//***************************************************************
// File: Shortest_Path_Unweighted.cpp
// Description:
//   Implements shortest path computation for unweighted graphs using BFS.
//
// Notes:
//   - BFS explores vertices level by level, so the first time a vertex
//     is discovered is always via the shortest path.
//   - distance[v] stores number of edges from start to v.
//   - parent[v] stores the previous vertex used to reach v.
//***************************************************************

#include "Shortest_Path_Unweighted.h"
#include <queue>
using namespace std;

// Function: bfsShortestPaths
// Parameters:
// const IGraph& graph - reference to any object implementing IGraph
// int start - starting vertex
// vector<int>& distance - output distances from start
// vector<int>& parent - output parent pointers
// Output:
// Fills distance and parent arrays
void bfsShortestPaths(const IGraph& graph,
                      int start,
                      vector<int>& distance,
                      vector<int>& parent) {
    int V = graph.getVertexCount();

    if (V == 0 || start < 0 || start >= V) {
        distance.clear();
        parent.clear();
        return;
    }

    distance.assign(V, -1);
    parent.assign(V, -1);

    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue;

            // If v has not been visited, we found the shortest path to it
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

// Function: reconstructPath
// Parameters:
// int start - starting vertex
// int target - destination vertex
// const vector<int>& parent - parent array produced by bfsShortestPaths
// Output:
// Returns path from start to target (inclusive)
vector<int> reconstructPath(int start,
                            int target,
                            const vector<int>& parent) {
    if (parent.empty()) return {};
    if (start < 0 || target < 0) return {};
    if (start >= (int)parent.size() || target >= (int)parent.size()) return {};

    if (start == target) return { start };

    vector<int> path;
    int cur = target;

    // Walk backwards from target to start
    while (cur != -1) {
        path.push_back(cur);
        if (cur == start) break;
        cur = parent[cur];
    }

    // If we never reached start, no valid path exists
    if (path.back() != start) return {};

    // Reverse path to get start -> target
    for (int i = 0, j = (int)path.size() - 1; i < j; i++, j--) {
        int tmp = path[i];
        path[i] = path[j];
        path[j] = tmp;
    }

    return path;
}
