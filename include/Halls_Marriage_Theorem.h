//***************************************************************
// File: Halls_Marriage_Theorem.h
// Description:
//   Declares functions to check Hall's Marriage Theorem on a
//   bipartite graph.
//
// Notes:
//   - Naive approach, suitable for small partitions
//***************************************************************

#ifndef HALLS_MARRIAGE_THEOREM_H
#define HALLS_MARRIAGE_THEOREM_H

#include "IGraph.h"
#include <vector>
using namespace std;

bool satisfiesHallCondition(const IGraph& graph, const vector<int>& partition);
bool hasPerfectMatchingHall(const IGraph& graph, const vector<int>& leftPartition, const vector<int>& rightPartition);

#endif
