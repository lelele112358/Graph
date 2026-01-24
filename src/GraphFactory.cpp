//***************************************************************
// File: GraphFactory.cpp
// Description:
//   Factory to create a graph dynamically using list or matrix.
//   Chooses implementation based on density and dynamic flag.
//
// Notes:
//   - Adapters wrap ListGraph/MatrixGraph into IGraph interface
//***************************************************************

#include "GraphFactory.h"
#include "List_Implementation_Graph.h"
#include "Matrix_Implementation_Graph.h"
#include <iostream>
using namespace std;

enum class GraphType { MATRIX, LIST };

static GraphType chooseGraphImplementation(bool isDense, bool isDynamic) {
    if (isDense && !isDynamic) return GraphType::MATRIX;
    return GraphType::LIST;
}

/* ---------- List Adapter ---------- */
class ListGraphAdapter : public IGraph {
private:
    ListGraph graph;
public:
    ListGraphAdapter(int V, bool directed) : graph(V, directed) {}
    bool addEdge(int u, int v) override { return graph.addEdge(u, v); }
    void display() const override { graph.display(); }
    int getVertexCount() const override { return graph.getVertexCount(); }
    bool isDirected() const override { return graph.isDirected(); }
    vector<int> getNeighbors(int u) const override { return graph.getNeighbors(u); }
};

/* ---------- Matrix Adapter ---------- */
class MatrixGraphAdapter : public IGraph {
private:
    MatrixGraph graph;
public:
    MatrixGraphAdapter(int V, bool directed) : graph(V, directed) {}
    bool addEdge(int u, int v) override { return graph.addEdge(u, v); }
    void display() const override { graph.display(); }
    int getVertexCount() const override { return graph.getVertexCount(); }
    bool isDirected() const override { return graph.isDirected(); }
    vector<int> getNeighbors(int u) const override { return graph.getNeighbors(u); }
};

/* ---------- Factory Function ---------- */
IGraph* selectAndCreateGraph() {
    int V, E; char dir, dense, dynamic;

    cout << "Enter number of vertices: "; cin >> V;
    cout << "Enter number of edges: "; cin >> E;
    cout << "Is the graph directed? (y/n): "; cin >> dir;
    cout << "Is the graph dense? (y/n): "; cin >> dense;
    cout << "Is the graph dynamic? (y/n): "; cin >> dynamic;

    bool isDirected = (dir == 'y' || dir == 'Y');
    bool isDense = (dense == 'y' || dense == 'Y');
    bool isDynamic = (dynamic == 'y' || dynamic == 'Y');

    GraphType type = chooseGraphImplementation(isDense, isDynamic);
    IGraph* graph = nullptr;

    if (type == GraphType::MATRIX) {
        cout << "Using adjacency matrix" << endl;
        graph = new MatrixGraphAdapter(V, isDirected);
    } else {
        cout << "Using adjacency list" << endl;
        graph = new ListGraphAdapter(V, isDirected);
    }

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if (!graph->addEdge(u, v)) {
            cout << "Invalid edge, re-enter" << endl;
            i--;
        }
    }

    return graph;
}
