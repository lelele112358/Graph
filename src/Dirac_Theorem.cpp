//***************************************************************
// File: Dirac_Theorem.cpp
// Description:
//   Implementation of Dirac's Theorem check.
//***************************************************************

#include "Dirac_Theorem.h"

#include <vector>
#include <unordered_set>
using namespace std;

// Function: detectSimple_Dirac
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns true if (best-effort):
//   - no self-loops
//   - no parallel edges (duplicate neighbors)
// Notes:
//   - This assumes adjacency lists represent edges directly.
static bool detectSimple_Dirac(const IGraph& g) {
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

// Function: analyzeDiracTheorem
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns DiracReport with:
//   - undirected/simple/applicable flags
//   - n, minDegree
//   - holds = (minDegree >= n/2) for n>=3
DiracReport analyzeDiracTheorem(const IGraph& g) {
    DiracReport r;

    r.n = g.getVertexCount();
    r.undirected = !g.isDirected();
    r.simple = detectSimple_Dirac(g);
    r.applicable = (r.undirected && r.simple && r.n >= 3);

    // Compute min degree
    r.minDegree = 0;
    if (r.n > 0) {
        r.minDegree = g.getOutDegree(0);
        for (int v = 1; v < r.n; v++) {
            int d = g.getOutDegree(v);
            if (d < r.minDegree) r.minDegree = d;
        }
    }

    // Dirac condition: minDegree >= n/2  <=>  2*minDegree >= n
    r.holds = (r.n >= 3) && (r.minDegree * 2 >= r.n);

    return r;
}

// Function: satisfiesDirac
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns true iff Dirac's theorem applies AND holds
bool satisfiesDirac(const IGraph& g) {
    DiracReport r = analyzeDiracTheorem(g);
    return r.applicable && r.holds;
}
