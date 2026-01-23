/* ****
*   File: GraphFactory.cpp
*   Description: Factory for creating graphs dynamically. Chooses between 
*                adjacency matrix and adjacency list implementations based
*                on graph density and dynamic behavior. Includes adapter classes
*                to unify interface access via IGraph.
**** */

#include "GraphFactory.h"
#include "List_Implementation_Graph.h"
#include "Matrix_Implementation_Graph.h"
#include <iostream>

using namespace std;

/* ---------- Graph Type Enum ---------- */
enum class GraphType {
    MATRIX,
    LIST
};

/* ---------- Implementation Selector ---------- */
// Chooses the graph representation based on density and dynamic requirement
static GraphType chooseGraphImplementation(bool isDense, bool dynamicGraph) {
    if (isDense && !dynamicGraph)
        return GraphType::MATRIX;
    return GraphType::LIST;
}

/* ---------- Adapters ---------- */
// Adapter to unify ListGraph to IGraph interface
class ListGraphAdapter : public IGraph {
private:
    ListGraph graph;

public:
    ListGraphAdapter(int V, bool directed)
        : graph(V, directed) {}

    bool addEdge(int u, int v) override {
        return graph.addEdge(u, v);
    }

    void display() const override {
        graph.display();
    }

    int getVertexCount() const override {
        return graph.getVertexCount();
    }

    bool isDirected() const override {
        return graph.isDirected();
    }

    vector<int> getNeighbors(int u) const override {
        return graph.getNeighbors(u);
    }
};

// Adapter to unify MatrixGraph to IGraph interface
class MatrixGraphAdapter : public IGraph {
private:
    MatrixGraph graph;

public:
    MatrixGraphAdapter(int V, bool directed)
        : graph(V, directed) {}

    bool addEdge(int u, int v) override {
        return graph.addEdge(u, v);
    }

    void display() const override {
        graph.display();
    }

    int getVertexCount() const override {
        return graph.getVertexCount();
    }

    bool isDirected() const override {
        return graph.isDirected();
    }

    vector<int> getNeighbors(int u) const override {
        return graph.getNeighbors(u);
    }
};

/* ---------- Factory Function ---------- */
// Prompts user input, chooses graph type, and returns a pointer to IGraph
IGraph* selectAndCreateGraph() {
    int V, E;
    char dir, dense, dynamic;

    cout << "Enter number of vertices: " << endl;
    cin >> V;

    cout << "Enter number of edges: " << endl;
    cin >> E;

    cout << "Is the graph directed? (y/n): " << endl;
    cin >> dir;

    cout << "Is the graph dense? (y/n): " << endl;
    cin >> dense;

    cout << "Is the graph dynamic? (y/n): " << endl;
    cin >> dynamic;

    bool directed = (dir == 'y' || dir == 'Y');
    bool isDense = (dense == 'y' || dense == 'Y');
    bool isDynamic = (dynamic == 'y' || dynamic == 'Y');

    GraphType type = chooseGraphImplementation(isDense, isDynamic);
    IGraph* graph = nullptr;

    if (type == GraphType::MATRIX) {
        cout << "Using adjacency matrix" << endl;
        graph = new MatrixGraphAdapter(V, directed);
    } else {
        cout << "Using adjacency list" << endl;
        graph = new ListGraphAdapter(V, directed);
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
