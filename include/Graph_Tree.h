//***************************************************************
// File: Graph_Tree.h
// Description:
//   Declares a function to determine if a graph is a tree.
//
// Notes:
//   - A tree must be undirected, connected, and acyclic
//***************************************************************

#ifndef GRAPH_TREE_H
#define GRAPH_TREE_H

#include "IGraph.h"

// Function: isTree
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns true if the graph is a tree, otherwise false
bool isTree(const IGraph& graph);

#endif
