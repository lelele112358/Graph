//***************************************************************
// File: SCC_Kosaraju.h
// Description:
//   Declares functions to find Strongly Connected Components (SCCs)
//   in a directed graph using Kosaraju's algorithm.
//
// Kosaraju's algorithm summary:
//   1) Run DFS on original graph to compute a finishing-time order
//   2) Reverse the graph
//   3) Run DFS in reverse finishing-time order on the reversed graph
//      Each DFS tree forms one SCC
//
// Notes:
//   - SCC is meaningful for directed graphs.
//   - For undirected graphs, SCCs match connected components.
//***************************************************************

#ifndef SCC_KOSARAJU_H
#define SCC_KOSARAJU_H

#include "IGraph.h"
#include <vector>
using namespace std;

// Function: kosarajuSCC
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// vector<int>& componentId - output array where componentId[v] is SCC index of v
// Output:
// Returns a list of SCCs, where each SCC is a vector of vertices
// Notes:
// - Works best for directed graphs
// - For undirected graphs, returns connected components as SCCs
vector<vector<int>> kosarajuSCC(const IGraph& graph, vector<int>& componentId);

#endif
