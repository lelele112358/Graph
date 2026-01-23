/*
 * Matrix_Implementation_Graph.cpp
 *
 * Description:
 *  This file implements the MatrixGraph class, which represents a graph
 *  using a V x V adjacency matrix.
 *
 *  Key features:
 *  - Constructor: Initializes an adjacency matrix with all entries set to 0.
 *  - Destructor: Deletes all dynamically allocated memory for the matrix.
 *  - addEdge(): Adds edges for directed or undirected graphs, while preventing
 *    duplicates and self-loops in undirected graphs.
 *  - display(): Prints the adjacency matrix in a readable format.
 *  - verifyUndirectedInvariants(): Checks symmetry and diagonal invariants for
 *    undirected graphs to ensure consistency.
 */
#include "Matrix_Implementation_Graph.h"
#include <iostream>
using namespace std;

#define endln endl

MatrixGraph::MatrixGraph(int vertices, bool isDirected)
    : V(vertices), E(0), directed(isDirected) {

    matrix = new int*[V];
    for (int i = 0; i < V; i++) {
        matrix[i] = new int[V];
        for (int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }
}

MatrixGraph::~MatrixGraph() {
    for (int i = 0; i < V; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool MatrixGraph::isValidVertex(int v) const {
    return v >= 0 && v < V;
}

bool MatrixGraph::addEdge(int u, int v) {
    if (!isValidVertex(u) || !isValidVertex(v)) {
        cout << "Vertex out of range." << endln;
        return false;
    }

    if (directed) {
        if (matrix[u][v] == 1) {
            cout << "Edge already exists." << endln;
            return false;
        }
        matrix[u][v] = 1;
        E++;
        return true;
    } else {
        if (u == v) {
            cout << "No self-loops in undirected graph." << endln;
            return false;
        }
        if (matrix[u][v] == 1) {
            cout << "Edge already exists." << endln;
            return false;
        }
        matrix[u][v] = 1;
        matrix[v][u] = 1; // ensure symmetry
        E++;
        return true;
    }
}

void MatrixGraph::display() const {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endln;
    }
}

void MatrixGraph::verifyUndirectedInvariants() const {
    if (directed) return;

    for (int i = 0; i < V; i++) {
        if (matrix[i][i] != 0) {
            cout << "Diagonal violation at (" << i << "," << i << ")" << endln;
        }
        for (int j = i + 1; j < V; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                cout << "Symmetry violation between " << i << " and " << j << endln;
            }
        }
    }
}
