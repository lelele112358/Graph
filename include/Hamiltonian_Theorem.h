//***************************************************************
// File: Hamiltonian_Theorem.h
// Description:
//   Combined analysis wrapper for Hamiltonicity sufficient
//   conditions using:
//     - Dirac's Theorem
//     - Ore's Theorem
//
// Notes:
//   - These are sufficient conditions, not necessary.
//   - If both fail, graph may still be Hamiltonian.
//***************************************************************

#ifndef HAMILTONIAN_THEOREM_H
#define HAMILTONIAN_THEOREM_H

#include "Dirac_Theorem.h"
#include "Ore_Theorem.h"

// Struct: HamiltonianTheoremReport
// Purpose:
//   One combined report for the CLI to display.
struct HamiltonianTheoremReport {
    int n;

    bool undirected;
    bool simple;
    bool applicable;

    DiracReport dirac;
    OreReport ore;

    bool guaranteedHamiltonian;
};

// Function: analyzeHamiltonianTheorems
// Parameters:
// const IGraph& g - graph reference
// Output:
// Returns HamiltonianTheoremReport containing:
//   - Dirac + Ore reports
//   - combined applicability flags
//   - guaranteedHamiltonian = (Dirac holds) OR (Ore holds)
HamiltonianTheoremReport analyzeHamiltonianTheorems(const IGraph& g);

#endif
