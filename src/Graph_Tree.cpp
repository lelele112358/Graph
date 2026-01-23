/* ****
*   File: Graph_Tree.cpp
*   Description: Implements a function to check whether a graph is a tree.
**** */

#include "Graph_Tree.h"
#include "Cycle_Detection.h"
#include "Graph_Connectivity.h"

#include <vector>
#include <queue>

using namespace std;

/* ---------- Public Interface ---------- */
bool isTree(const IGraph& graph) {
    // Trees must be undirected
    if (graph.isDirected())
        return false;

    // Must be connected
    if (!isConnected(graph))
        return false;

    // Must be acyclic
    if (hasCycle(graph))
        return false;

    return true;
}
