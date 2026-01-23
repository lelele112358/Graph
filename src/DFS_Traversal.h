/* ****
*   File: DFS_Traversal.h
*   Description: Declares a function to perform Depth-First Search (DFS)
*                traversal on a graph. Works with any graph implementing IGraph.
*                DFS explores as far as possible along each branch before backtracking.
**** */

#ifndef DFS_TRAVERSAL_H
#define DFS_TRAVERSAL_H

#include "IGraph.h"

// Function: DFS
// Parameters:
//    const IGraph& graph - reference to any object implementing IGraph
//    int start - starting vertex for traversal
// Output: prints DFS traversal order to console
void DFS(const IGraph& graph, int start);

#endif // DFS_TRAVERSAL_H
