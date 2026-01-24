//***************************************************************
// File: Halls_Marriage_Theorem.cpp
// Description:
//   Implements Hall's Marriage Theorem check for bipartite graphs.
//
// Notes:
//   - Checks all subsets of partitions (naive, exponential time)
//***************************************************************

#include "Halls_Marriage_Theorem.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

static vector<int> neighborsOfSet(const IGraph& graph, const vector<int>& subset) {
    vector<int> neighbors;
    for (int u : subset) {
        for (int v : graph.getNeighbors(u)) {
            if (find(neighbors.begin(), neighbors.end(), v) == neighbors.end()) {
                neighbors.push_back(v);
            }
        }
    }
    return neighbors;
}

bool satisfiesHallCondition(const IGraph& graph, const vector<int>& partition) {
    int n = partition.size();
    if (n > 30) {
        cout << "Partition too large, skipping Hall check" << endl;
        return false;
    }

    int subsetCount = 1 << n;
    for (int mask = 1; mask < subsetCount; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) subset.push_back(partition[i]);
        }
        vector<int> neighbors = neighborsOfSet(graph, subset);
        if (neighbors.size() < subset.size()) return false;
    }
    return true;
}

bool hasPerfectMatchingHall(const IGraph& graph, const vector<int>& leftPartition, const vector<int>& rightPartition) {
    if (leftPartition.size() != rightPartition.size()) return false;
    return satisfiesHallCondition(graph, leftPartition) && satisfiesHallCondition(graph, rightPartition);
}
