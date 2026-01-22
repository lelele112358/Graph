#include "Matrix_Implementation_Graph.h"
#include <iostream>

using namespace std;

GraphMatrix::GraphMatrix(int vertices)
    : V(vertices), matrix(vertices, vector<int>(vertices, 0)) {}

void GraphMatrix::addEdge(int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void GraphMatrix::display() const {
    cout << "\nAdjacency Matrix:\n";
    for (auto row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
