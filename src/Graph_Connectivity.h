/* ****
*   File: Graph_Connectivity.h
*   Description: Declares a function to check whether a graph is connected.
**** */

#ifndef GRAPH_CONNECTIVITY_H
#define GRAPH_CONNECTIVITY_H

#include "IGraph.h"

// Function: isConnected
// Description: Determines whether the given graph is connected
// Parameters:
//    const IGraph& graph - reference to any object implementing IGraph
// Returns: true if the graph is connected, false otherwise
bool isConnected(const IGraph& graph);

#endif 
