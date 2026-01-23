/* ****
*   File: GraphFactory.h
*   Description: Header file declaring the factory function to create a graph.
*                Returns a pointer to an IGraph, choosing between adjacency
*                list or adjacency matrix based on user input.
**** */

#ifndef GRAPH_FACTORY_H
#define GRAPH_FACTORY_H

#include "IGraph.h"

// Function: selectAndCreateGraph
// Description: Prompts user for graph parameters, selects an implementation
//              (matrix or list), and returns a pointer to the created graph.
IGraph* selectAndCreateGraph();

#endif // GRAPH_FACTORY_H
