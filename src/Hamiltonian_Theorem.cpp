//***************************************************************
// File: Hamiltonian_Theorem.cpp
// Description:
//   Aggregates Dirac + Ore theorem checks into one report.
//***************************************************************

#include "Hamiltonian_Theorem.h"

// Function: analyzeHamiltonianTheorems
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns combined HamiltonianTheoremReport
HamiltonianTheoremReport analyzeHamiltonianTheorems(const IGraph& g) {
    HamiltonianTheoremReport r;

    r.n = g.getVertexCount();

    r.dirac = analyzeDiracTheorem(g);
    r.ore   = analyzeOreTheorem(g);

    // Shared assumptions (simple + undirected + n>=3)
    r.undirected = r.dirac.undirected;
    r.simple = r.dirac.simple;
    r.applicable = (r.undirected && r.simple && r.n >= 3);

    r.guaranteedHamiltonian =
        (r.dirac.applicable && r.dirac.holds) ||
        (r.ore.applicable && r.ore.holds);

    return r;
}
