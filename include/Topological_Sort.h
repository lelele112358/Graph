//***************************************************************
// File: Topological_Sort.h
// Description:
//   Declares functions to perform topological sorting on a
//   directed graph using Kahn's algorithm (BFS-based).
//
// Notes:
//   - Topological ordering exists only for directed acyclic graphs (DAGs)
//   - If a cycle exists, no valid ordering is possible
//***************************************************************

#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "IGraph.h"
#include <vector>
using namespace std;

// Function: topologicalSort
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// vector<int>& order - output vector storing topological order
// Output:
// Returns true if topological ordering exists, false if graph has a cycle
// Notes:
// - If graph is undirected, this function returns false
bool topologicalSort(const IGraph& graph, vector<int>& order);

#endif
