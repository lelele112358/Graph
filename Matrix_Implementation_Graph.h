#ifndef MATRIX_IMPLEMENTATION_GRAPH_H
#define MATRIX_IMPLEMENTATION_GRAPH_H

#include <vector>
using namespace std;

class GraphMatrix {
private:
    int V;
    vector<vector<int>> matrix;

public:
    GraphMatrix(int vertices);
    void addEdge(int u, int v);
    void display() const;
};

#endif
