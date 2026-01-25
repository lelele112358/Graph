//***************************************************************
// File: Shortest_Path_Unweighted.h
// Description:
//   Declares shortest path utilities for unweighted graphs using BFS.
//
//   This module provides:
//     - distance array from a start vertex
//     - parent array to reconstruct shortest paths
//     - path reconstruction from start to target
//
// Notes:
//   - Works with any IGraph implementation
//   - All edges are assumed to have equal weight (unweighted)
//***************************************************************

#ifndef SHORTEST_PATH_UNWEIGHTED_H
#define SHORTEST_PATH_UNWEIGHTED_H

#include "IGraph.h"
#include <vector>
using namespace std;

// Function: bfsShortestPaths
// Parameters:
// const IGraph& graph - reference to any object implementing IGraph
// int start - starting vertex
// vector<int>& distance - output distances, distance[v] is edges from start to v
// vector<int>& parent - output parents, parent[v] is previous node on shortest path
// Output:
// Fills distance and parent arrays
// Notes:
// - If start is invalid, distance and parent are cleared
// - Unreachable vertices have distance = -1 and parent = -1
void bfsShortestPaths(const IGraph& graph,
                      int start,
                      vector<int>& distance,
                      vector<int>& parent);

// Function: reconstructPath
// Parameters:
// int start - starting vertex
// int target - destination vertex
// const vector<int>& parent - parent array produced by bfsShortestPaths
// Output:
// Returns shortest path as a list of vertices from start to target (inclusive)
// Notes:
// - Returns empty vector if no path exists or input is invalid
vector<int> reconstructPath(int start,
                            int target,
                            const vector<int>& parent);

#endif
