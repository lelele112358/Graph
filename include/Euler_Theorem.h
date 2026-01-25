//***************************************************************
// File: Euler_Theorem.h
// Description:
//   Declares a function to determine if an Euler path or Euler
//   circuit exists in a graph.
//
// Notes:
//   - Undirected: uses odd-degree rule + connectivity on non-isolated vertices
//   - Directed: uses in/out degree rule + strong connectivity check
//***************************************************************

#ifndef EULER_THEOREM_H
#define EULER_THEOREM_H

#include "IGraph.h"

// Function: hasEulerPathOrCircuit
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns true if Euler path or Euler circuit exists
bool hasEulerPathOrCircuit(const IGraph& graph);

#endif
