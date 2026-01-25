//***************************************************************
// File: Graph_Tree.cpp
// Description:
//   Implements a function to check whether a graph is a tree.
//
// Notes:
//   - Uses isConnected + hasCycle checks
//   - Directed graphs are automatically not trees in this project
//***************************************************************

#include "Graph_Tree.h"
#include "Graph_Connectivity.h"
#include "Cycle_Detection.h"

// Function: isTree
// Parameters:
// const IGraph& graph - reference to a graph implementing IGraph
// Output:
// Returns true if graph is undirected, connected, and acyclic
bool isTree(const IGraph& graph) {
    if (graph.isDirected()) return false;
    if (!isConnected(graph)) return false;
    if (hasCycle(graph)) return false;
    return true;
}
