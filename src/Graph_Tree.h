/* ****
*   File: Graph_Tree.h
*   Description: Declares a function to determine whether a graph is a tree.
*                A graph is a tree if it is undirected, connected, and acyclic.
**** */

#ifndef GRAPH_TREE_H
#define GRAPH_TREE_H

#include "IGraph.h"

// Function: isTree
// Description: Determines whether the given graph is a tree
// Parameters:
//    const IGraph& graph - reference to any object implementing IGraph
// Returns: true if the graph is a tree, false otherwise
bool isTree(const IGraph& graph);

#endif 
