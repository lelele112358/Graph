//***************************************************************
// File: Graph_Tree.cpp
// Description:
//   Implements a function to check whether a graph is a tree.
//
// Notes:
//   - Uses connectivity and cycle detection
//***************************************************************

#include "Graph_Tree.h"
#include "Graph_Connectivity.h"
#include "Cycle_Detection.h"
using namespace std;

bool isTree(const IGraph& graph) {
    if (graph.isDirected()) return false;
    if (!isConnected(graph)) return false;
    if (hasCycle(graph)) return false;
    return true;
}
