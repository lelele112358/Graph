//***************************************************************
// File: Graph_Bipartite.cpp
// Description:
//   Implements bipartite check using BFS coloring.
//   Extracts left and right partitions of a bipartite graph.
//
// Notes:
//   - Returns false if any conflict found in coloring
//***************************************************************

#include "Graph_Bipartite.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool isBipartite(const IGraph& graph) {
    int V = graph.getVertexCount();
    vector<int> color(V, -1);

    for (int start = 0; start < V; ++start) {
        if (color[start] != -1) continue;

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph.getNeighbors(u)) {
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

vector<int> getLeftPartition(const IGraph& graph) {
    int V = graph.getVertexCount();
    vector<int> color(V, -1);
    queue<int> q;

    for (int start = 0; start < V; ++start) {
        if (color[start] != -1) continue;

        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph.getNeighbors(u)) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
    }

    vector<int> left;
    for (int i = 0; i < V; ++i) {
        if (color[i] == 0) left.push_back(i);
    }
    return left;
}

vector<int> getRightPartition(const IGraph& graph) {
    int V = graph.getVertexCount();
    vector<int> left = getLeftPartition(graph);
    vector<bool> isLeft(V, false);
    for (int u : left) isLeft[u] = true;

    vector<int> right;
    for (int i = 0; i < V; ++i) {
        if (!isLeft[i]) right.push_back(i);
    }
    return right;
}
