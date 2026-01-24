//***************************************************************
// File: Graph_Bipartite.h
// Description:
//   Declares functions to check if a graph is bipartite using BFS
//   coloring and to extract left/right partitions.
//
// Notes:
//   - Works with any IGraph implementation
//***************************************************************

#ifndef GRAPH_BIPARTITE_H
#define GRAPH_BIPARTITE_H

#include "IGraph.h"
#include <vector>
using namespace std;

bool isBipartite(const IGraph& graph);
vector<int> getLeftPartition(const IGraph& graph);
vector<int> getRightPartition(const IGraph& graph);

#endif
