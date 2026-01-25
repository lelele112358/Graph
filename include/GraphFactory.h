//***************************************************************
// File: GraphFactory.h
// Description:
//   Declares the factory function that creates a graph based on
//   user input (list vs matrix).
//
// Notes:
//   - Returns IGraph* allocated with new
//   - Caller must delete the returned object
//***************************************************************

#ifndef GRAPH_FACTORY_H
#define GRAPH_FACTORY_H

#include "IGraph.h"

// Function: selectAndCreateGraph
// Parameters:
// None
// Output:
// Returns a dynamically allocated graph (IGraph*) built from user input
IGraph* selectAndCreateGraph();

#endif
