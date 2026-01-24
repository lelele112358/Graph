//***************************************************************
// File: BFS_Traversal.h
// Description:
//   Declares a function to perform Breadth-First Search (BFS)
//   traversal on a graph implementing IGraph.
//
// Notes:
//   - BFS visits nodes level by level starting from start vertex
//***************************************************************

#ifndef BFS_TRAVERSAL_H
#define BFS_TRAVERSAL_H

#include "IGraph.h"

void BFS(const IGraph& graph, int start);

#endif
