//***************************************************************
// File: Halls_Marriage_Theorem.cpp
// Description:
//   Implements Hall's Marriage Theorem check for bipartite graphs.
//
// Notes:
//   - This is a naive algorithm that checks all subsets of one side
//     (exponential time). It is fine for small partitions.
//   - Key detail: when counting neighbors, we only count neighbors
//     on the opposite partition. That avoids false positives.
//***************************************************************

#include "Halls_Marriage_Theorem.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Function: neighborsOfSubsetRestricted
// Parameters:
// const IGraph& graph - graph reference
// const vector<int>& subset - chosen vertices from one partition
// const vector<bool>& allowed - allowed[v] == true means v is a valid neighbor
// Output:
// Returns the unique neighbor set N(subset) restricted to allowed vertices
static vector<int> neighborsOfSubsetRestricted(const IGraph& graph,
                                              const vector<int>& subset,
                                              const vector<bool>& allowed) {
    int V = graph.getVertexCount();
    vector<int> neighbors;

    for (int u : subset) {
        if (u < 0 || u >= V) continue;

        for (int v : graph.getNeighbors(u)) {
            if (v < 0 || v >= V) continue;
            if (!allowed[v]) continue;

            if (find(neighbors.begin(), neighbors.end(), v) == neighbors.end()) {
                neighbors.push_back(v);
            }
        }
    }

    return neighbors;
}

// Function: satisfiesHallConditionInternal
// Parameters:
// const IGraph& graph - graph reference
// const vector<int>& side - the partition being checked
// const vector<bool>& oppositeMask - marks vertices that are valid neighbors
// Output:
// Returns true if Hall holds for "side" against the opposite partition
static bool satisfiesHallConditionInternal(const IGraph& graph,
                                          const vector<int>& side,
                                          const vector<bool>& oppositeMask) {
    int n = (int)side.size();

    // Small safety limit: subset enumeration is 2^n
    if (n > 25) {
        cout << "Hall check skipped: partition too large (" << n << ")" << endl;
        return false;
    }

    int subsetCount = 1 << n;

    for (int mask = 1; mask < subsetCount; mask++) {
        vector<int> subset;
        subset.reserve(n);

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) subset.push_back(side[i]);
        }

        vector<int> nbrs = neighborsOfSubsetRestricted(graph, subset, oppositeMask);
        if ((int)nbrs.size() < (int)subset.size()) return false;
    }

    return true;
}

// Function: satisfiesHallCondition
// Parameters:
// const IGraph& graph - graph reference
// const vector<int>& partition - side to check
// Output:
// Returns true if Hall condition holds for this side
// Notes:
// - This fallback assumes the "other side" is all vertices not in partition.
// - For the real bipartite use-case, prefer hasPerfectMatchingHall().
bool satisfiesHallCondition(const IGraph& graph, const vector<int>& partition) {
    int V = graph.getVertexCount();
    vector<bool> inPartition(V, false);

    for (int u : partition) {
        if (u < 0 || u >= V) continue;
        inPartition[u] = true;
    }

    vector<bool> oppositeMask(V, false);
    for (int i = 0; i < V; i++) {
        if (!inPartition[i]) oppositeMask[i] = true;
    }

    return satisfiesHallConditionInternal(graph, partition, oppositeMask);
}

// Function: hasPerfectMatchingHall
// Parameters:
// const IGraph& graph - graph reference
// const vector<int>& leftPartition - left side
// const vector<int>& rightPartition - right side
// Output:
// Returns true if Hall guarantees a perfect matching exists
// Notes:
// - Standard Hall check is done on the left side only
bool hasPerfectMatchingHall(const IGraph& graph,
                           const vector<int>& leftPartition,
                           const vector<int>& rightPartition) {
    if (leftPartition.size() != rightPartition.size()) return false;

    int V = graph.getVertexCount();
    vector<bool> rightMask(V, false);

    for (int v : rightPartition) {
        if (v < 0 || v >= V) continue;
        rightMask[v] = true;
    }

    return satisfiesHallConditionInternal(graph, leftPartition, rightMask);
}
