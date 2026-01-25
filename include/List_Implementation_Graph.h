//***************************************************************
// File: List_Implementation_Graph.h
// Description:
//   Adjacency list graph implementation that conforms to IGraph.
//   This version is memory-efficient for sparse graphs.
//
// Notes:
//   - Works for directed and undirected graphs
//   - Stores neighbors in adjacency lists
//***************************************************************

#ifndef LIST_IMPLEMENTATION_GRAPH_H
#define LIST_IMPLEMENTATION_GRAPH_H

#include "IGraph.h"
#include <vector>
#include <iostream>
using namespace std;

class ListGraph : public IGraph {
private:
    int V;
    bool directed;
    vector<vector<int>> adj;

    // Function: isValidVertex
    // Parameters:
    // int v - vertex index
    // Output:
    // Returns true if v is within [0, V-1]
    bool isValidVertex(int v) const;

public:
    // Function: ListGraph (Constructor)
    // Parameters:
    // int vertices - number of vertices
    // bool isDirected - true for directed graphs
    // Output:
    // Constructs an empty adjacency list graph
    ListGraph(int vertices, bool isDirected);

    // Function: addEdge
    // Parameters:
    // int u - source vertex
    // int v - destination vertex
    // Output:
    // Returns true if edge is added successfully, false if invalid
    bool addEdge(int u, int v) override;

    // Function: display
    // Parameters:
    // None
    // Output:
    // Prints the adjacency list to standard output
    void display() const override;

    // Function: getVertexCount
    // Parameters:
    // None
    // Output:
    // Returns the number of vertices in the graph
    int getVertexCount() const override;

    // Function: isDirected
    // Parameters:
    // None
    // Output:
    // Returns true if graph is directed
    bool isDirected() const override;

    // Function: getNeighbors
    // Parameters:
    // int u - vertex to query
    // Output:
    // Returns a vector of neighbors of u (empty if u invalid)
    vector<int> getNeighbors(int u) const override;

    // Function: getOutDegree
    // Parameters:
    // int v - vertex to query
    // Output:
    // Returns out-degree of v (0 if invalid)
    int getOutDegree(int v) const override;

    // Function: getInDegree
    // Parameters:
    // int v - vertex to query
    // Output:
    // Returns in-degree of v (0 if invalid)
    int getInDegree(int v) const override;
};

#endif
