//***************************************************************
// File: Halls_Marriage_Theorem.h
// Description:
//   Declares functions to check Hall's Marriage Theorem on a
//   bipartite graph.
//
// Notes:
//   - Naive subset checking (exponential), intended for small graphs
//***************************************************************

#ifndef HALLS_MARRIAGE_THEOREM_H
#define HALLS_MARRIAGE_THEOREM_H

#include "IGraph.h"
#include <vector>
using namespace std;

// Function: satisfiesHallCondition
// Parameters:
// const IGraph& graph - graph reference (assumed bipartite)
// const vector<int>& partition - one side of the bipartition
// Output:
// Returns true if Hall's condition holds for this side, false otherwise
// Notes:
// - This version assumes "the other side" is all vertices NOT in partition.
// - For best correctness, use hasPerfectMatchingHall() with both partitions.
bool satisfiesHallCondition(const IGraph& graph, const vector<int>& partition);

// Function: hasPerfectMatchingHall
// Parameters:
// const IGraph& graph - graph reference (must be bipartite)
// const vector<int>& leftPartition - left side vertices
// const vector<int>& rightPartition - right side vertices
// Output:
// Returns true if a perfect matching must exist (Hall), false otherwise
// Notes:
// - Checks Hall only on the left side (the standard usage)
bool hasPerfectMatchingHall(const IGraph& graph,
                           const vector<int>& leftPartition,
                           const vector<int>& rightPartition);

#endif
