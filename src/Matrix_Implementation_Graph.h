/*
 * Matrix_Implementation_Graph.h
 *
 * Description:
 *  This header file declares the MatrixGraph class, which represents a graph
 *  using a V x V adjacency matrix.
 *
 *  - Encapsulates internal data:
 *      * V: number of vertices
 *      * E: number of edges
 *      * directed: true if the graph is directed
 *      * matrix: pointer to the dynamically allocated adjacency matrix
 *  - Provides methods to:
 *      * addEdge(int u, int v): Adds an edge to the graph.
 *      * display(): Prints the adjacency matrix.
 *      * verifyUndirectedInvariants(): Ensures symmetry and no self-loops in undirected graphs.
 */
#ifndef MATRIX_IMPLEMENTATION_GRAPH_H
#define MATRIX_IMPLEMENTATION_GRAPH_H

class MatrixGraph {
private:
    int V;       // number of vertices
    int E;       // number of edges
    bool directed;
    int** matrix;

    bool isValidVertex(int v) const;

public:
    MatrixGraph(int vertices, bool isDirected);
    ~MatrixGraph();

    bool addEdge(int u, int v);
    void display() const;
    void verifyUndirectedInvariants() const;
};

#endif
