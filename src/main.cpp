/*
 * main.cpp
 *
 * Description:
 *  This file contains the entry point of the program.
 *
 *  - Uses selectAndCreateGraph() to prompt the user for graph properties and
 *    create the appropriate graph implementation (adjacency matrix or list).
 *  - Reads edges from the user and builds the graph.
 *  - Displays the graph using the display() method.
 *  - Cleans up dynamically allocated memory to prevent memory leaks.
 */
#include "Graph_Implementation_Selector.h"

int main() {
    IGraph* graph = selectAndCreateGraph();
    graph->display();
    delete graph;
    return 0;
}

