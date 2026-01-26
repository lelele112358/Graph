//***************************************************************
// File: Ore_Theorem.h
// Description:
//   Ore's Theorem (Hamiltonicity sufficient condition).
//
// Theorem (informal):
//   For a simple, undirected graph with n >= 3,
//   if for every non-adjacent pair (u,v):
//     deg(u) + deg(v) >= n
//   then the graph is Hamiltonian.
//
// Notes:
//   - If the condition FAILS, the graph may still be Hamiltonian.
//   - This module does NOT construct a Hamiltonian cycle.
//***************************************************************

#ifndef ORE_THEOREM_H
#define ORE_THEOREM_H

#include "IGraph.h"

// Struct: OreReport
// Purpose:
//   Stores a detailed analysis result for Ore's Theorem.
struct OreReport {
    bool undirected;
    bool simple;
    bool applicable;

    int n;
    int violations;   // number of non-adjacent pairs that violate Ore
    bool holds;
};

// Function: satisfiesOre
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns true if:
//   - graph is undirected, simple, n>=3, AND
//   - Ore condition holds (no violating non-adjacent pairs)
bool satisfiesOre(const IGraph& g);

// Function: analyzeOreTheorem
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns OreReport with applicability + violation count
OreReport analyzeOreTheorem(const IGraph& g);

#endif
