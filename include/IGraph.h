//***************************************************************
// File: IGraph.h
// Description:
//   Abstract interface for graph algorithms. Provides a unified
//   interface for graph operations so that algorithms work with
//   either adjacency list or adjacency matrix implementations.
//
// Notes:
//   - Algorithms depend ONLY on this interface, not on adjacency
//     list or matrix details.
//***************************************************************

#ifndef IGRAPH_H
#define IGRAPH_H

#include <vector>
using namespace std;

/* ---------- IGraph Interface ---------- */
class IGraph {
public:
    virtual ~IGraph() = default;

    // Function: addEdge
    // Parameters: int u, int v
    // Output: Adds an edge u->v; returns false if invalid or duplicate
    virtual bool addEdge(int u, int v) = 0;

    // Function: display
    // Output: prints the graph to console
    virtual void display() const = 0;

    // Function: getVertexCount
    // Output: returns the number of vertices
    virtual int getVertexCount() const = 0;

    // Function: isDirected
    // Output: true if directed, false otherwise
    virtual bool isDirected() const = 0;

    // Function: getNeighbors
    // Parameters: int u
    // Output: returns vector of neighbors of u
    virtual vector<int> getNeighbors(int u) const = 0;
};

#endif // IGRAPH_H
