//***************************************************************
// File: Graph_Connectivity.h
// Description:
//   Declares a function to check whether a graph is connected.
//   Works for any graph implementing IGraph interface.
//
// Notes:
//   - Uses BFS traversal for connectivity check
//***************************************************************

#ifndef GRAPH_CONNECTIVITY_H
#define GRAPH_CONNECTIVITY_H

#include "IGraph.h"

bool isConnected(const IGraph& graph);

#endif
