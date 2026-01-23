/* ****
*   File: List_Implementation_Graph.h
*   Description: Header file for ListGraph class implementing a graph
*                using adjacency lists. Provides methods for adding edges,
*                displaying the graph, and accessing neighbors.
**** */

#ifndef LIST_IMPLEMENTATION_GRAPH_H
#define LIST_IMPLEMENTATION_GRAPH_H

#include <vector>
#include <iostream>

using namespace std;

/* ---------- ListGraph Class ---------- */
// Graph implementation using adjacency list
class ListGraph {
private:
    int V;                          // Number of vertices
    bool directed;                  // True if graph is directed
    vector<vector<int>> adj;        // Adjacency list

    // Helper functions
    bool isValidVertex(int v) const;    // Check if vertex is valid
    bool edgeExists(int u, int v) const; // Check if edge exists

public:
    // Constructor
    ListGraph(int vertices, bool isDirected);

    // Core graph operations
    bool addEdge(int u, int v);         // Add edge u -> v
    void display() const;               // Display adjacency list

    // Accessors needed by adapters / algorithms
    int getVertexCount() const;         // Return number of vertices
    bool isDirected() const;            // Return if graph is directed
    vector<int> getNeighbors(int u) const; // Return neighbors of vertex u
};

#endif // LIST_IMPLEMENTATION_GRAPH_H
