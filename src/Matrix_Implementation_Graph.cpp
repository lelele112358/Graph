//***************************************************************
// File: Matrix_Implementation_Graph.cpp
// Description:
//   Implements an adjacency matrix graph that conforms to the IGraph interface.
//   Provides edge insertion, display, neighbor queries, and degree calculations.
//
// Notes:
//   - getNeighbors scans a full row (O(V))
//   - getOutDegree scans a full row (O(V))
//   - getInDegree scans a full column (O(V))
//   - Best for dense graphs or when you need fast edge existence checks
//***************************************************************

#include "Matrix_Implementation_Graph.h"

// Function: isValidVertex
// Parameters:
// int v - vertex index
// Output:
// Returns true if v is within [0, V-1], otherwise false
bool MatrixGraph::isValidVertex(int v) const {
    return v >= 0 && v < V;
}

// Function: MatrixGraph (Constructor)
// Parameters:
// int vertices - number of vertices
// bool isDirected - true if graph is directed, false if undirected
// Output:
// Builds an empty adjacency matrix graph (all zeros)
MatrixGraph::MatrixGraph(int vertices, bool isDirected)
    : V(vertices),
      directed(isDirected),
      matrix(vertices, vector<int>(vertices, 0)) {}

// Function: addEdge
// Parameters:
// int u - source vertex
// int v - destination vertex
// Output:
// Returns true if edge is added successfully, false if invalid vertices
// Notes:
// - Undirected graphs store both (u,v) and (v,u)
bool MatrixGraph::addEdge(int u, int v) {
    if (!isValidVertex(u) || !isValidVertex(v)) return false;

    matrix[u][v] = 1;

    if (!directed) {
        matrix[v][u] = 1;
    }

    return true;
}

// Function: display
// Parameters:
// None
// Output:
// Prints the adjacency matrix (V x V) to standard output
// Notes:
// - Row i and column j show whether an edge i -> j exists (1) or not (0)
void MatrixGraph::display() const {
    cout << "Adjacency Matrix:" << endl;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function: getVertexCount
// Parameters:
// None
// Output:
// Returns the number of vertices in the graph
int MatrixGraph::getVertexCount() const {
    return V;
}

// Function: isDirected
// Parameters:
// None
// Output:
// Returns true if graph is directed, false otherwise
bool MatrixGraph::isDirected() const {
    return directed;
}

// Function: getNeighbors
// Parameters:
// int u - vertex to query
// Output:
// Returns a vector of neighbors of u (empty if u is invalid)
vector<int> MatrixGraph::getNeighbors(int u) const {
    if (!isValidVertex(u)) return {};

    vector<int> neighbors;
    for (int v = 0; v < V; v++) {
        if (matrix[u][v] != 0) neighbors.push_back(v);
    }
    return neighbors;
}

// Function: getOutDegree
// Parameters:
// int v - vertex to query
// Output:
// Returns out-degree of v (0 if invalid)
// Notes:
// - For undirected graphs, this equals the degree of v
int MatrixGraph::getOutDegree(int v) const {
    if (!isValidVertex(v)) return 0;

    int count = 0;
    for (int j = 0; j < V; j++) {
        if (matrix[v][j] != 0) count++;
    }
    return count;
}

// Function: getInDegree
// Parameters:
// int v - vertex to query
// Output:
// Returns in-degree of v (0 if invalid)
// Notes:
// - For undirected graphs, this will match out-degree
int MatrixGraph::getInDegree(int v) const {
    if (!isValidVertex(v)) return 0;

    int count = 0;
    for (int i = 0; i < V; i++) {
        if (matrix[i][v] != 0) count++;
    }
    return count;
}
