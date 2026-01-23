/* ****
*   File: Graph_Bipartite.h
*   Description: Header file declaring the isBipartite function, which checks
*                if a graph is bipartite using BFS coloring.
**** */

#ifndef GRAPH_BIPARTITE_H
#define GRAPH_BIPARTITE_H

#include "IGraph.h"
#include <vector>
#include <queue>

// Function: isBipartite
// Description: Determines if a graph is bipartite
// Parameters:
//    const IGraph& graph - reference to any object implementing IGraph
// Returns: true if bipartite, false otherwise
bool isBipartite(const IGraph& graph);

#endif // GRAPH_BIPARTITE_H
