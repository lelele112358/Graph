/* ****
*   File: main.cpp
*   Description: Main program to create a graph via user input, display it,
*                check if it is a tree, check for cycles, check bipartite,
*                and perform BFS/DFS traversals.
**** */

#include "GraphFactory.h"
#include "Graph_Bipartite.h"
#include "Cycle_Detection.h"
#include "Graph_Tree.h"
#include "BFS_Traversal.h"
#include "DFS_Traversal.h"

#include <iostream>

using namespace std;

int main() {
    // 1. Create graph using factory based on user input
    IGraph* graph = selectAndCreateGraph();

    cout << "-----------------------------" << endl;

    // 2. Display the created graph
    graph->display();

    cout << "-----------------------------" << endl;

    // 3. Check if the graph is a tree
    if (isTree(*graph)) {
        cout << "The graph is a tree." << endl;
        cout << "Since it is a tree, it is automatically bipartite and contains no cycles." << endl;
    } else {
        cout << "The graph is NOT a tree." << endl;

    // 4. Check if the graph has cycles
    if (hasCycle(*graph)) {
        cout << "The graph contains at least one cycle." << endl;
    } else {
        cout << "The graph does NOT contain a cycle." << endl;
    }

    // 5. Check if the graph is bipartite
    if (isBipartite(*graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is NOT bipartite." << endl;
    }
}


    cout << "-----------------------------" << endl;

    // 6. Perform BFS traversal starting from vertex 0
    BFS(*graph, 0);

    // 7. Perform DFS traversal starting from vertex 0
    DFS(*graph, 0);

    cout << "-----------------------------" << endl;

    // 8. Free dynamically allocated graph
    delete graph;

    return 0;
}
