//***************************************************************
// File: Graph_Bipartite.h
// Description:
//   Declares functions to check if a graph is bipartite using BFS
//   coloring, and to extract left/right partitions.
//
// Notes:
//   - Intended mainly for undirected graphs
//   - For directed graphs, this treats edges as given by getNeighbors()
//***************************************************************

#ifndef GRAPH_BIPARTITE_H
#define GRAPH_BIPARTITE_H

#include "IGraph.h"
#include <vector>
using namespace std;

// Function: isBipartite
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns true if graph can be colored with 2 colors without conflict
bool isBipartite(const IGraph& graph);

// Function: getLeftPartition
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns the list of vertices colored as "left" (color 0)
// Notes:
// - If graph is disconnected, this includes color 0 from all components
vector<int> getLeftPartition(const IGraph& graph);

// Function: getRightPartition
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns the list of vertices colored as "right" (color 1)
// Notes:
// - If graph is disconnected, this includes color 1 from all components
vector<int> getRightPartition(const IGraph& graph);

#endif
