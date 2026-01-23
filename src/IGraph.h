/* ****
*   File: IGraph.h
*   Description: Abstract interface for graph algorithms. Provides a unified
*                interface for graph operations so that algorithms work with
*                either adjacency list or matrix implementations.
**** */

#ifndef IGRAPH_H
#define IGRAPH_H

#include <vector>

using namespace std;

/* ---------- IGraph Interface ---------- */
// Abstract interface for graph algorithms
// Algorithms depend ONLY on this interface, not on adjacency list or matrix details
class IGraph {
public:
    virtual ~IGraph() = default;

    // Core graph operations
    virtual bool addEdge(int u, int v) = 0;   // Adds an edge from u to v
    virtual void display() const = 0;         // Displays the graph

    // Required for graph algorithms
    virtual int getVertexCount() const = 0;   // Returns number of vertices
    virtual bool isDirected() const = 0;      // Returns true if graph is directed
    virtual vector<int> getNeighbors(int u) const = 0; // Returns neighbors of u
};

#endif // IGRAPH_H
