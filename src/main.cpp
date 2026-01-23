/* ****
*   File: main.cpp
*   Description: Main program to create a graph via user input, display it,
*                and check whether it is bipartite.
**** */

#include "GraphFactory.h"
#include "Graph_Bipartite.h"
#include <iostream>

using namespace std;

int main() {
    // Create graph using factory based on user input
    IGraph* graph = selectAndCreateGraph();

    // Display the created graph
    graph->display();

    // Check if the graph is bipartite
    if (isBipartite(*graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is NOT bipartite." << endl;
    }

    // Free dynamically allocated graph
    delete graph;
    return 0;
}
