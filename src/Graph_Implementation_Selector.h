/*
 * Graph_Implementation_Selector.h
 *
 * Description:
 *  This header file declares the functionality for selecting and creating
 *  graph implementations based on graph properties such as density and 
 *  dynamic operations.
 *
 *  - chooseGraphImplementation(): Determines the optimal graph representation
 *    (adjacency matrix or adjacency list) based on whether the graph is dense
 *    or subject to frequent insertions/deletions.
 *  - IGraph: An abstract interface that allows polymorphic access to graphs.
 *  - ListGraphAdapter / MatrixGraphAdapter: Adapter classes that connect
 *    concrete graph implementations (ListGraph, MatrixGraph) to the IGraph interface.
 *  - selectAndCreateGraph(): Handles user input and creates an instance of the
 *    appropriate graph implementation, returning an IGraph pointer.
 */
#ifndef GRAPH_IMPLEMENTATION_SELECTOR_H
#define GRAPH_IMPLEMENTATION_SELECTOR_H

#include "Matrix_Implementation_Graph.h"
#include "List_Implementation_Graph.h"
#include <iostream>
using namespace std;

#define endln endl

enum class GraphType {
    MATRIX,
    LIST
};

GraphType chooseGraphImplementation(bool isDense, bool dynamicGraph);

class IGraph {
public:
    virtual ~IGraph() = default;
    virtual bool addEdge(int u, int v) = 0;
    virtual void display() const = 0;
};

class ListGraphAdapter : public IGraph, public ListGraph {
public:
    ListGraphAdapter(int V, bool directed) : ListGraph(V, directed) {}

    bool addEdge(int u, int v) override {
        return ListGraph::addEdge(u, v);
    }

    void display() const override {
        ListGraph::display();
    }
};

class MatrixGraphAdapter : public IGraph, public MatrixGraph {
public:
    MatrixGraphAdapter(int V, bool directed) : MatrixGraph(V, directed) {}

    bool addEdge(int u, int v) override {
        return MatrixGraph::addEdge(u, v);
    }

    void display() const override {
        MatrixGraph::display();
    }
};

IGraph* selectAndCreateGraph();

#endif

