//***************************************************************
// File: IGraph.h
// Description:
//   Abstract graph interface used by all algorithms in the project.
//   Supports traversal, connectivity, bipartite checks, cycle
//   detection, Euler's Theorem, and future extensions.
//***************************************************************

#ifndef IGRAPH_H
#define IGRAPH_H

#include <vector>
using namespace std;

class IGraph {
public:
    virtual ~IGraph() = default;

    // Core operations
    virtual bool addEdge(int u, int v) = 0;
    virtual void display() const = 0;

    // Structure queries
    virtual int getVertexCount() const = 0;
    virtual bool isDirected() const = 0;
    virtual vector<int> getNeighbors(int u) const = 0;

    // Degree queries (REQUIRED)
    virtual int getOutDegree(int v) const = 0;
    virtual int getInDegree(int v) const = 0;
};

#endif
