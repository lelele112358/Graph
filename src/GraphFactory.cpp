//***************************************************************
// File: GraphFactory.cpp
// Description:
//   Factory that creates a graph dynamically (list or matrix)
//   based on user input.
//
// Notes:
//   - Matrix is chosen for dense, non-dynamic graphs
//   - List is chosen otherwise
//***************************************************************

#include "GraphFactory.h"
#include "List_Implementation_Graph.h"
#include "Matrix_Implementation_Graph.h"

#include <iostream>
using namespace std;

// Function: chooseGraphImplementation
// Parameters:
// bool isDense - true if graph is dense
// bool isDynamic - true if graph changes frequently
// Output:
// Returns true if matrix should be used, false for list
static bool chooseMatrix(bool isDense, bool isDynamic) {
    if (isDense && !isDynamic) return true;
    return false;
}

// Function: selectAndCreateGraph
// Parameters:
// None
// Output:
// Returns a dynamically allocated IGraph* based on user choices
// Notes:
// - Caller must delete the returned pointer
IGraph* selectAndCreateGraph() {
    int V, E;
    char dir, dense, dynamic;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Is the graph directed? (y/n): ";
    cin >> dir;

    cout << "Is the graph dense? (y/n): ";
    cin >> dense;

    cout << "Is the graph dynamic? (y/n): ";
    cin >> dynamic;

    bool isDirected = (dir == 'y' || dir == 'Y');
    bool isDense = (dense == 'y' || dense == 'Y');
    bool isDynamic = (dynamic == 'y' || dynamic == 'Y');

    IGraph* graph = nullptr;

    if (chooseMatrix(isDense, isDynamic)) {
        cout << "Using adjacency matrix" << endl;
        graph = new MatrixGraph(V, isDirected);
    } else {
        cout << "Using adjacency list" << endl;
        graph = new ListGraph(V, isDirected);
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
