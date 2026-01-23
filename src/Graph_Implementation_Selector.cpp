/*
 * Graph_Implementation_Selector.cpp
 *
 * Description:
 *  This file provides functionality to select and create a graph implementation
 *  (adjacency matrix or adjacency list) based on user input and graph properties.
 *
 *  - chooseGraphImplementation(): Determines the optimal graph representation
 *    based on density and dynamic nature of the graph.
 *  - selectAndCreateGraph(): 
 *      1. Prompts the user for graph parameters (number of vertices, edges, directed, dense, dynamic).
 *      2. Selects the appropriate graph implementation using chooseGraphImplementation().
 *      3. Instantiates the corresponding adapter (MatrixGraphAdapter or ListGraphAdapter).
 *      4. Collects edge input from the user and adds them to the graph.
 *
 *  Returns:
 *    Pointer to IGraph for polymorphic handling in main or other client code.
 */
#include "Graph_Implementation_Selector.h"

GraphType chooseGraphImplementation(bool isDense, bool dynamicGraph) {
    // - If the graph is dense AND NOT frequently modified, use matrix
    // - Otherwise, use adjacency list
    if (isDense && !dynamicGraph) {
        return GraphType::MATRIX;
    }
    return GraphType::LIST;
}

IGraph* selectAndCreateGraph() {
    int V, E;
    char dir, dense, dynamic;

    cout << "Enter number of vertices: " << endln;
    cin >> V;

    cout << "Enter number of edges: " << endln;
    cin >> E;

    cout << "Is the graph directed? (y/n): " << endln;
    cin >> dir;

    cout << "Is the graph dense? (y/n): " << endln;// Since we can calculate density of the graph, but this question is here just to let user have a choice whether the graph is dense or not. Cause no accurate number between 0-1 actually state the graph is dense
    cin >> dense;

    cout << "Is the graph dynamic (frequent insert/delete)? (y/n): " << endln;
    cin >> dynamic;

    bool directed = (dir == 'y' || dir == 'Y');
    bool isDense = (dense == 'y' || dense == 'Y');
    bool isDynamic = (dynamic == 'y' || dynamic == 'Y');

    GraphType type = chooseGraphImplementation(isDense, isDynamic);

    if (type == GraphType::MATRIX) {
        cout << "Using adjacency matrix" << endln;
        MatrixGraphAdapter* graph = new MatrixGraphAdapter(V, directed);

        cout << "Enter edges (u v):" << endln;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if (!graph->addEdge(u, v)) i--; // repeat if invalid
        }

        return graph;
    } else {
        cout << "Using adjacency list" << endln;
        ListGraphAdapter* graph = new ListGraphAdapter(V, directed);

        cout << "Enter edges (u v):" << endln;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if (!graph->addEdge(u, v)) i--; // repeat if invalid
        }

        return graph;
    }
}

