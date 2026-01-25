//***************************************************************
// File: Matrix_Implementation_Graph.h
// Description:
//   Adjacency matrix graph implementation that conforms to IGraph.
//   This version is fast for edge-existence queries.
//
// Notes:
//   - Best for dense graphs
//   - Uses matrix[u][v] = 1 when edge exists
//***************************************************************

#ifndef MATRIX_IMPLEMENTATION_GRAPH_H
#define MATRIX_IMPLEMENTATION_GRAPH_H

#include "IGraph.h"
#include <vector>
#include <iostream>
using namespace std;

class MatrixGraph : public IGraph {
private:
    int V;
    bool directed;
    vector<vector<int>> matrix;

    // Function: isValidVertex
    // Parameters:
    // int v - vertex index
    // Output:
    // Returns true if v is within [0, V-1]
    bool isValidVertex(int v) const;

public:
    // Function: MatrixGraph (Constructor)
    // Parameters:
    // int vertices - number of vertices
    // bool isDirected - directed flag
    // Output:
    // Constructs an empty adjacency matrix graph
    MatrixGraph(int vertices, bool isDirected);

    // Function: addEdge
    // Parameters:
    // int u - source
    // int v - destination
    // Output:
    // Returns true if edge is added successfully
    bool addEdge(int u, int v) override;

    // Function: display
    // Parameters:
    // None
    // Output:
    // Prints neighbors for each vertex
    void display() const override;

    // Function: getVertexCount
    // Parameters:
    // None
    // Output:
    // Returns number of vertices
    int getVertexCount() const override;

    // Function: isDirected
    // Parameters:
    // None
    // Output:
    // Returns directed flag
    bool isDirected() const override;

    // Function: getNeighbors
    // Parameters:
    // int u - vertex
    // Output:
    // Returns vector of neighbors of u
    vector<int> getNeighbors(int u) const override;

    // Function: getOutDegree
    // Parameters:
    // int v - vertex
    // Output:
    // Returns out-degree of v
    int getOutDegree(int v) const override;

    // Function: getInDegree
    // Parameters:
    // int v - vertex
    // Output:
    // Returns in-degree of v
    int getInDegree(int v) const override;
};

#endif
