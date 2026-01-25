//***************************************************************
// File: Cycle_Detection.h
// Description:
//   Declares a function to detect cycles in directed and
//   undirected graphs.
//
// Notes:
//   - Undirected: DFS with parent tracking
//   - Directed: DFS with recursion stack detection
//***************************************************************

#ifndef CYCLE_DETECTION_H
#define CYCLE_DETECTION_H

#include "IGraph.h"

// Function: hasCycle
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns true if any cycle exists, otherwise false
bool hasCycle(const IGraph& graph);

#endif
