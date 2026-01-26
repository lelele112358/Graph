//***************************************************************
// File: Ore_Theorem.cpp
// Description:
//   Implementation of Ore's Theorem check.
//***************************************************************

#include "Ore_Theorem.h"

#include <vector>
#include <unordered_set>
using namespace std;

// Function: detectSimple_Ore
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns true if (best-effort):
//   - no self-loops
//   - no parallel edges (duplicate neighbors)
static bool detectSimple_Ore(const IGraph& g) {
    int n = g.getVertexCount();

    for (int u = 0; u < n; u++) {
        vector<int> nbrs = g.getNeighbors(u);
        unordered_set<int> seen;

        for (int v : nbrs) {
            if (v == u) return false;         // self-loop
            if (seen.count(v)) return false;  // parallel edge
            seen.insert(v);
        }
    }
    return true;
}

// Function: buildAdjMatrix_Ore
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns adjacency matrix adj[u][v] (1 if edge exists, else 0)
// Notes:
//   - For undirected graphs, we mirror edges defensively.
static vector<vector<char>> buildAdjMatrix_Ore(const IGraph& g) {
    int n = g.getVertexCount();
    vector<vector<char>> adj(n, vector<char>(n, 0));

    for (int u = 0; u < n; u++) {
        vector<int> nbrs = g.getNeighbors(u);
        for (int v : nbrs) {
            if (v < 0 || v >= n) continue;
            adj[u][v] = 1;

            if (!g.isDirected()) {
                adj[v][u] = 1;
            }
        }
    }

    return adj;
}

// Function: analyzeOreTheorem
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns OreReport with:
//   - undirected/simple/applicable flags
//   - n
//   - violations count
//   - holds = (violations == 0) for n>=3
OreReport analyzeOreTheorem(const IGraph& g) {
    OreReport r;

    r.n = g.getVertexCount();
    r.undirected = !g.isDirected();
    r.simple = detectSimple_Ore(g);
    r.applicable = (r.undirected && r.simple && r.n >= 3);

    r.violations = 0;
    r.holds = (r.n >= 3);

    if (r.n < 3) return r;

    // Degree array
    vector<int> deg(r.n);
    for (int v = 0; v < r.n; v++) {
        deg[v] = g.getOutDegree(v);
    }

    // Adjacency matrix for O(1) adjacency checks
    vector<vector<char>> adj = buildAdjMatrix_Ore(g);

    // Check all non-adjacent pairs u < v
    for (int u = 0; u < r.n; u++) {
        for (int v = u + 1; v < r.n; v++) {
            if (adj[u][v]) continue;

            if (deg[u] + deg[v] < r.n) {
                r.violations++;
            }
        }
    }

    r.holds = (r.violations == 0);
    return r;
}

// Function: satisfiesOre
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns true iff Ore's theorem applies AND holds
bool satisfiesOre(const IGraph& g) {
    OreReport r = analyzeOreTheorem(g);
    return r.applicable && r.holds;
}
