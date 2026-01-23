/* ****
*   File: Cycle_Detection.h
*   Description: Declares functions to detect cycles in directed and
*                undirected graphs using DFS.
**** */

#ifndef CYCLE_DETECTION_H
#define CYCLE_DETECTION_H

#include "IGraph.h"

// Function: hasCycle
// Description: Determines whether the given graph contains a cycle.
//              Automatically handles directed and undirected graphs.
// Parameters:
//    const IGraph& graph - reference to any object implementing IGraph
// Returns: true if a cycle exists, false otherwise
bool hasCycle(const IGraph& graph);

#endif // CYCLE_DETECTION_H
