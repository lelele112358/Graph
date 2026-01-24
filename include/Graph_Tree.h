//***************************************************************
// File: Graph_Tree.h
// Description:
//   Declares a function to determine if a graph is a tree.
//
// Notes:
//   - Graph must be undirected, connected, and acyclic
//***************************************************************

#ifndef GRAPH_TREE_H
#define GRAPH_TREE_H

#include "IGraph.h"

bool isTree(const IGraph& graph);

#endif
