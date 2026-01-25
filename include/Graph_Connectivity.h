//***************************************************************
// File: Graph_Connectivity.h
// Description:
//   Declares a function to check whether a graph is connected.
//
// Notes:
//   - For undirected graphs: checks normal connectivity
//   - For directed graphs: checks weak connectivity (treat edges as undirected)
//***************************************************************

#ifndef GRAPH_CONNECTIVITY_H
#define GRAPH_CONNECTIVITY_H

#include "IGraph.h"

// Function: isConnected
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns true if all vertices are connected (single component)
// Notes:
// - Empty graph is considered connected
bool isConnected(const IGraph& graph);

#endif
