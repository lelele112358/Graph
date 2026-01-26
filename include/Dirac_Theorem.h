//***************************************************************
// File: Dirac_Theorem.h
// Description:
//   Dirac's Theorem (Hamiltonicity sufficient condition).
//
// Theorem (informal):
//   For a simple, undirected graph with n >= 3,
//   if every vertex has degree >= n/2,
//   then the graph is Hamiltonian.
//
// Notes:
//   - If the condition FAILS, the graph may still be Hamiltonian.
//   - This module does NOT construct a Hamiltonian cycle.
//***************************************************************

#ifndef DIRAC_THEOREM_H
#define DIRAC_THEOREM_H

#include "IGraph.h"

// Struct: DiracReport
// Purpose:
//   Stores a detailed analysis result for Dirac's Theorem.
// Notes:
//   - "simple" is best-effort detection (no self-loops, no duplicates).
struct DiracReport {
    bool undirected;
    bool simple;
    bool applicable;

    int n;
    int minDegree;
    bool holds;
};

// Function: satisfiesDirac
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns true if:
//   - graph is undirected, simple, n>=3, AND
//   - Dirac condition holds (minDegree >= n/2)
bool satisfiesDirac(const IGraph& g);

// Function: analyzeDiracTheorem
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns DiracReport with applicability + computed stats
DiracReport analyzeDiracTheorem(const IGraph& g);

#endif
