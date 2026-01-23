/* ****
*   File: BFS_Traversal.h
*   Description: Declares a function to perform Breadth-First Search (BFS)
*                traversal on a graph. Works with any graph implementing IGraph.
*                BFS visits nodes level by level starting from a given vertex.
**** */

#ifndef BFS_TRAVERSAL_H
#define BFS_TRAVERSAL_H

#include "IGraph.h"

// Function: BFS
// Parameters:
//    const IGraph& graph - reference to any object implementing IGraph
//    int start - starting vertex for traversal
// Output: prints BFS traversal order to console
void BFS(const IGraph& graph, int start);

#endif // BFS_TRAVERSAL_H
