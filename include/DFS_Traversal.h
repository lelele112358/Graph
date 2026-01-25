//***************************************************************
// File: DFS_Traversal.h
// Description:
//   Declares the Depth-First Search (DFS) traversal function.
//
// Notes:
//   - Works with any graph that implements the IGraph interface
//***************************************************************

#ifndef DFS_TRAVERSAL_H
#define DFS_TRAVERSAL_H

#include "IGraph.h"

// Function: DFS
// Parameters:
// const IGraph& graph - reference to any object implementing IGraph
// int start - starting vertex for traversal
// Output:
// Prints the DFS traversal order to standard output
// Notes:
// - Does nothing if start is out of bounds
void DFS(const IGraph& graph, int start);

#endif
