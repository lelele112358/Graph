//***************************************************************
// File: BFS_Traversal.h
// Description:
//   Declares the Breadth-First Search (BFS) traversal function.
//
// Notes:
//   - Works with any graph that implements the IGraph interface
//***************************************************************

#ifndef BFS_TRAVERSAL_H
#define BFS_TRAVERSAL_H

#include "IGraph.h"

// Function: BFS
// Parameters:
// const IGraph& graph - reference to any object implementing IGraph
// int start - starting vertex for traversal
// Output:
// Prints the BFS traversal order to standard output
// Notes:
// - Does nothing if start is out of bounds
void BFS(const IGraph& graph, int start);

#endif
