//***************************************************************
// File: Graphviz_Export.cpp
// Description:
//   Implements Graphviz DOT export for any IGraph object.
//
// Notes:
//   - To avoid printing undirected edges twice, we only emit edges
//     where u <= v (for undirected graphs).
//   - Directed graphs emit all edges u -> v as stored.
//***************************************************************

#include "Graphviz_Export.h"
#include <fstream>
#include <vector>
using namespace std;

// Function: exportToDotFile
// Parameters:
// const IGraph& graph - reference to any object implementing IGraph
// const string& filename - output DOT file name
// Output:
// Returns true if writing succeeds, false otherwise
bool exportToDotFile(const IGraph& graph, const string& filename) {
    int V = graph.getVertexCount();

    ofstream out(filename);
    if (!out.is_open()) return false;

    bool directed = graph.isDirected();
    string header = directed ? "digraph" : "graph";
    string arrow  = directed ? "->" : "--";

    out << header << " G {\n";
    out << "  rankdir=LR;\n";
    out << "  node [shape=circle];\n\n";

    // Print all vertices (even isolated ones)
    for (int i = 0; i < V; i++) {
        out << "  " << i << ";\n";
    }
    out << "\n";

    // Print edges
    for (int u = 0; u < V; u++) {
        vector<int> neighbors = graph.getNeighbors(u);

        for (int v : neighbors) {
            if (v < 0 || v >= V) continue;

            // For undirected graphs, avoid duplicates: print only u <= v
            if (!directed && u > v) continue;

            out << "  " << u << " " << arrow << " " << v << ";\n";
        }
    }

    out << "}\n";
    out.close();
    return true;
}
