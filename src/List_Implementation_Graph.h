/*
 * List_Implementation_Graph.h
 *
 * Description:
 *  This header file declares the ListGraph class, which represents a graph
 *  using an adjacency list with linked lists for each vertex.
 *
 *  - Node: Struct representing a node in a linked list (adjacency list entry).
 *  - ListGraph: Concrete graph class with:
 *      * addEdge(int u, int v): Adds an edge to the graph.
 *      * display(): Prints the adjacency list.
 *  - Internal details such as the number of vertices, directed flag, and
 *    adjacency array are encapsulated as private members.
 *  - Helper methods (isValidVertex, edgeExists) are private to ensure safe
 *    and correct graph operations.
 */
#ifndef LIST_IMPLEMENTATION_GRAPH_H
#define LIST_IMPLEMENTATION_GRAPH_H

#include <vector>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

class ListGraph {
private:
    int V;          // number of vertices
    bool directed;  // true if graph is directed
    Node** adj;     // adjacency lists

    bool isValidVertex(int v) const;
    bool edgeExists(int u, int v) const;

public:
    ListGraph(int vertices, bool isDirected);
    ~ListGraph();

    bool addEdge(int u, int v);
    void display() const;
};

#endif
