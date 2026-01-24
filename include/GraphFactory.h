//***************************************************************
// File: GraphFactory.h
// Description:
//   Declares the factory function to create a graph and return
//   pointer to IGraph. Supports adjacency list or matrix.
//
// Notes:
//   - User chooses graph properties interactively
//***************************************************************

#ifndef GRAPH_FACTORY_H
#define GRAPH_FACTORY_H

#include "IGraph.h"

IGraph* selectAndCreateGraph();

#endif
