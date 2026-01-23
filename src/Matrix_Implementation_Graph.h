/* ****
*   File: Matrix_Implementation_Graph.h
*   Description: Header file for MatrixGraph class implementing a graph
*                using an adjacency matrix. Provides methods for adding edges,
*                displaying the graph, and accessing neighbors.
**** */

#ifndef MATRIX_IMPLEMENTATION_GRAPH_H
#define MATRIX_IMPLEMENTATION_GRAPH_H

#include <vector>
#include <iostream>

using namespace std;

/* ---------- MatrixGraph Class ---------- */
// Graph implementation using adjacency matrix
class MatrixGraph {
private:
    int V;                          // Number of vertices
    bool directed;                  // True if graph is directed
    vector<vector<int>> matrix;     // Adjacency matrix

    // Helper function
    bool isValidVertex(int v) const; // Check if vertex is valid

public:
    // Constructor
    MatrixGraph(int vertices, bool isDirected);

    // Core graph operations
    bool addEdge(int u, int v);      // Add edge u -> v
    void display() const;            // Display adjacency matrix

    // Accessors needed by adapters / algorithms
    int getVertexCount() const;       // Return number of vertices
    bool isDirected() const;          // Return if graph is directed
    vector<int> getNeighbors(int u) const; // Return neighbors of vertex u
};

#endif // MATRIX_IMPLEMENTATION_GRAPH_H
