//***************************************************************
// File: DFS_Traversal.h
// Description:
//   Declares a function to perform Depth-First Search (DFS)
//   traversal on a graph implementing IGraph.
//
// Notes:
//   - DFS explores as far as possible along each branch before backtracking
//***************************************************************

#ifndef DFS_TRAVERSAL_H
#define DFS_TRAVERSAL_H

#include "IGraph.h"

void DFS(const IGraph& graph, int start);

#endif
