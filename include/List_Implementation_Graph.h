//***************************************************************
// File: List_Implementation_Graph.h
// Description:
//   Header file for ListGraph class implementing a graph
//   using adjacency lists. Provides methods for adding edges,
//   displaying the graph, and accessing neighbors.
//
// Notes:
//   - Efficient for sparse graphs
//   - Works for directed and undirected graphs
//***************************************************************

#ifndef LIST_IMPLEMENTATION_GRAPH_H
#define LIST_IMPLEMENTATION_GRAPH_H

#include <vector>
#include <iostream>
using namespace std;

/* ---------- ListGraph Class ---------- */
class ListGraph {
private:
    int V;                    // Number of vertices
    bool directed;            // true if directed
    vector<vector<int>> adj;  // adjacency list

    bool isValidVertex(int v) const;    // Helper to check vertex index
    bool edgeExists(int u, int v) const; // Helper to check duplicate edge

public:
    // Function: ListGraph constructor
    // Parameters:
    //   int vertices - number of vertices
    //   bool isDirected - true if graph is directed
    ListGraph(int vertices, bool isDirected);

    // Function: addEdge
    // Parameters: int u, int v
    // Output: adds edge u -> v
    bool addEdge(int u, int v);

    // Function: display
    // Parameters: none
    // Output: prints adjacency list to console
    void display() const;

    // Accessors
    int getVertexCount() const;
    bool isDirected() const;
    vector<int> getNeighbors(int u) const;
};

#endif // LIST_IMPLEMENTATION_GRAPH_H
