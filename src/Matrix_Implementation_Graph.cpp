//***************************************************************
// File: Matrix_Implementation_Graph.cpp
// Description:
//   Implements a graph using adjacency matrix. Provides core
//   operations such as adding edges, displaying the matrix,
//   and retrieving neighbors.
//
// Notes:
//   - Efficient for dense graphs
//***************************************************************

#include "Matrix_Implementation_Graph.h"
using namespace std;

/* ---------- Helper ---------- */
bool MatrixGraph::isValidVertex(int v) const {
    return v >= 0 && v < V;
}

/* ---------- Constructor ---------- */
MatrixGraph::MatrixGraph(int vertices, bool isDirected)
    : V(vertices), directed(isDirected), matrix(vertices, vector<int>(vertices, 0)) {}

/* ---------- Core Operations ---------- */
bool MatrixGraph::addEdge(int u, int v) {
    if (!isValidVertex(u) || !isValidVertex(v)) {
        cout << "Vertex out of range" << endl;
        return false;
    }
    if (matrix[u][v] == 1) {
        cout << "Edge already exists" << endl;
        return false;
    }
    matrix[u][v] = 1;
    if (!directed && u != v) matrix[v][u] = 1;
    return true;
}

void MatrixGraph::display() const {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/* ---------- Accessors ---------- */
int MatrixGraph::getVertexCount() const { return V; }
bool MatrixGraph::isDirected() const { return directed; }

vector<int> MatrixGraph::getNeighbors(int u) const {
    vector<int> neighbors;
    if (!isValidVertex(u)) return neighbors;
    for (int v = 0; v < V; v++) {
        if (matrix[u][v] == 1) neighbors.push_back(v);
    }
    return neighbors;
}
