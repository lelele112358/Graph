//***************************************************************
// File: Matrix_Implementation_Graph.h
// Description:
//   Header file for MatrixGraph class implementing a graph
//   using adjacency matrix. Provides methods for adding edges,
//   displaying the graph, and accessing neighbors.
//
// Notes:
//   - Efficient for dense graphs
//***************************************************************

#ifndef MATRIX_IMPLEMENTATION_GRAPH_H
#define MATRIX_IMPLEMENTATION_GRAPH_H

#include <vector>
#include <iostream>
using namespace std;

class MatrixGraph {
private:
    int V;
    bool directed;
    vector<vector<int>> matrix;

    bool isValidVertex(int v) const;

public:
    // Constructor
    MatrixGraph(int vertices, bool isDirected);

    // Core operations
    bool addEdge(int u, int v);
    void display() const;

    // Accessors
    int getVertexCount() const;
    bool isDirected() const;
    vector<int> getNeighbors(int u) const;
};

#endif
