//***************************************************************
// File: Graphviz_Export.h
// Description:
//   Declares functions to export any IGraph object into Graphviz
//   DOT format (.dot file). This makes it easy to visualize graphs
//   using Graphviz tools.
//
// Example:
//   dot -Tpng graph.dot -o graph.png
//
// Notes:
//   - Works for directed and undirected graphs
//   - Uses only IGraph interface (no dependence on graph type)
//***************************************************************

#ifndef GRAPHVIZ_EXPORT_H
#define GRAPHVIZ_EXPORT_H

#include "IGraph.h"
#include <string>
using namespace std;

// Function: exportToDotFile
// Parameters:
// const IGraph& graph - reference to any object implementing IGraph
// const string& filename - output filename (example: "graph.dot")
// Output:
// Returns true if file is written successfully, false otherwise
// Notes:
// - For undirected graphs, uses "graph" and "--"
// - For directed graphs, uses "digraph" and "->"
bool exportToDotFile(const IGraph& graph, const string& filename);

#endif
