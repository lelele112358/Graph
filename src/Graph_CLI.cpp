//***************************************************************
// File: Graph_CLI.cpp
// Description:
//   Implements the Command Line Interface (CLI) controller for the
//   Graph project. This file owns all "run..." style helper functions
//   and keeps main.cpp lightweight.
//
// Included Features:
//   - Tree check
//   - Cycle detection
//   - Bipartite check + partitions
//   - BFS / DFS traversal
//   - Hall's Marriage Theorem (requires bipartite)
//   - Euler path/circuit existence
//   - Graphviz DOT export
//   - Unweighted shortest path (BFS distance + path reconstruction)
//   - Topological sort (directed DAGs)
//   - Strongly Connected Components (Kosaraju)
//
// Notes:
//   - This file is UI-focused (input/output).
//   - Algorithms remain in their own modules.
//***************************************************************

#include "Graph_CLI.h"

#include "Graph_Bipartite.h"
#include "Graph_Tree.h"
#include "Cycle_Detection.h"
#include "BFS_Traversal.h"
#include "DFS_Traversal.h"
#include "Halls_Marriage_Theorem.h"
#include "Euler_Theorem.h"
#include "Graphviz_Export.h"
#include "Shortest_Path_Unweighted.h"
#include "Topological_Sort.h"
#include "SCC_Kosaraju.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function: printDivider
// Parameters:
// None
// Output:
// Prints a visual divider line to the console
static void printDivider() {
    cout << "-----------------------------" << endl;
}

// Function: askYesNo
// Parameters:
// const string& question - prompt to show the user
// Output:
// Returns true if user enters y/Y, otherwise false
// Notes:
// - Keeps the CLI code readable and consistent
static bool askYesNo(const string& question) {
    char c;
    cout << question;
    cin >> c;
    return (c == 'y' || c == 'Y');
}

// Function: runTreeCheck
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Prints whether the graph is a tree
static void runTreeCheck(const IGraph& graph) {
    if (isTree(graph)) {
        cout << "Graph is a tree (connected + acyclic + undirected)." << endl;
    } else {
        cout << "Graph is NOT a tree." << endl;
    }
}

// Function: runCycleCheck
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Prints whether the graph contains a cycle
static void runCycleCheck(const IGraph& graph) {
    if (hasCycle(graph)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does NOT contain a cycle." << endl;
    }
}

// Function: runBipartiteCheck
// Parameters:
// const IGraph& graph - graph reference
// bool& outBipartite - output flag storing bipartite result
// Output:
// Prints bipartite result and sets outBipartite accordingly
static void runBipartiteCheck(const IGraph& graph, bool& outBipartite) {
    outBipartite = isBipartite(graph);
    cout << (outBipartite ? "Graph is bipartite." : "Graph is NOT bipartite.") << endl;

    if (outBipartite) {
        vector<int> left = getLeftPartition(graph);
        vector<int> right = getRightPartition(graph);

        cout << "Left partition: ";
        for (int v : left) cout << v << " ";
        cout << endl;

        cout << "Right partition: ";
        for (int v : right) cout << v << " ";
        cout << endl;
    }
}

// Function: runTraversals
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Runs BFS and DFS starting from a user-chosen vertex
// Notes:
// - BFS() and DFS() already print their own labels and traversal order
static void runTraversals(const IGraph& graph) {
    int start;
    cout << "Enter starting vertex for BFS/DFS: ";
    cin >> start;

    BFS(graph, start);
    DFS(graph, start);
}

// Function: runHallCheck
// Parameters:
// const IGraph& graph - graph reference
// bool bipartite - whether the graph is bipartite
// Output:
// Prints Hall theorem result (or explains why it cannot be applied)
static void runHallCheck(const IGraph& graph, bool bipartite) {
    if (!bipartite) {
        cout << "Cannot apply Hall's theorem: graph not bipartite." << endl;
        return;
    }

    vector<int> left = getLeftPartition(graph);
    vector<int> right = getRightPartition(graph);

    if (hasPerfectMatchingHall(graph, left, right)) {
        cout << "Hall check passed: a perfect matching must exist." << endl;
    } else {
        cout << "Hall check failed: no perfect matching guaranteed." << endl;
    }
}

// Function: runEulerCheck
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Prints whether an Euler path or circuit exists
static void runEulerCheck(const IGraph& graph) {
    if (hasEulerPathOrCircuit(graph)) {
        cout << "Graph has an Euler path or an Euler circuit." << endl;
    } else {
        cout << "Graph does NOT have an Euler path or Euler circuit." << endl;
    }
}

// Function: runGraphvizExport
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Prompts for a filename and exports to Graphviz DOT format
static void runGraphvizExport(const IGraph& graph) {
    string filename;
    cout << "Enter output DOT filename (example: graph.dot): ";
    cin >> filename;

    if (exportToDotFile(graph, filename)) {
        cout << "DOT file saved: " << filename << endl;
        cout << "Tip: dot -Tpng " << filename << " -o graph.png" << endl;
    } else {
        cout << "Failed to write DOT file." << endl;
    }
}

// Function: runShortestPath
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Computes BFS shortest path and prints distance + reconstructed path
static void runShortestPath(const IGraph& graph) {
    int start, target;
    cout << "Enter start vertex: ";
    cin >> start;
    cout << "Enter target vertex: ";
    cin >> target;

    vector<int> dist, parent;
    bfsShortestPaths(graph, start, dist, parent);

    if (dist.empty()) {
        cout << "Invalid start vertex." << endl;
        return;
    }

    if (target < 0 || target >= (int)dist.size()) {
        cout << "Invalid target vertex." << endl;
        return;
    }

    if (dist[target] == -1) {
        cout << "No path exists from " << start << " to " << target << "." << endl;
        return;
    }

    cout << "Shortest distance from " << start << " to " << target
         << " is " << dist[target] << " edges." << endl;

    vector<int> path = reconstructPath(start, target, parent);
    cout << "Path: ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 < (int)path.size()) cout << " -> ";
    }
    cout << endl;
}

// Function: runTopologicalSort
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Prints a topological order if it exists
static void runTopologicalSort(const IGraph& graph) {
    vector<int> order;

    if (!topologicalSort(graph, order)) {
        cout << "Topological sort not possible (graph is undirected or contains a cycle)." << endl;
        return;
    }

    cout << "Topological Order: ";
    for (int i = 0; i < (int)order.size(); i++) {
        cout << order[i];
        if (i + 1 < (int)order.size()) cout << " -> ";
    }
    cout << endl;
}

// Function: runSCCKosaraju
// Parameters:
// const IGraph& graph - graph reference
// Output:
// Finds SCCs and prints each component
static void runSCCKosaraju(const IGraph& graph) {
    if (!graph.isDirected()) {
        cout << "SCC is mainly for directed graphs (undirected SCC = connected components)." << endl;
    }

    vector<int> compId;
    vector<vector<int>> sccs = kosarajuSCC(graph, compId);

    cout << "Strongly Connected Components (" << (int)sccs.size() << "):" << endl;
    for (int i = 0; i < (int)sccs.size(); i++) {
        cout << "SCC " << i << ": ";
        for (int v : sccs[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// Function: runGraphCLI
// Parameters:
// IGraph& graph - reference to a graph created by GraphFactory
// Output:
// Runs the interactive console program and prints results
void runGraphCLI(IGraph& graph) {
    printDivider();
    graph.display();
    printDivider();

    bool doTree      = askYesNo("Check if graph is a tree? (y/n): ");
    bool doCycle     = askYesNo("Check if graph has cycles? (y/n): ");
    bool doBipartite = askYesNo("Check if graph is bipartite? (y/n): ");
    bool doTraversal = askYesNo("Perform BFS/DFS traversals? (y/n): ");
    bool doHall      = askYesNo("Check Hall's Marriage Theorem? (y/n): ");
    bool doEuler     = askYesNo("Check Euler path/circuit existence? (y/n): ");
    bool doDot       = askYesNo("Export graph to Graphviz (.dot)? (y/n): ");
    bool doShortest  = askYesNo("Find shortest path using BFS? (y/n): ");
    bool doTopo      = askYesNo("Perform topological sort? (y/n): ");
    bool doSCC       = askYesNo("Find strongly connected components (SCC)? (y/n): ");

    printDivider();

    bool bipartite = false;

    if (doTree) {
        runTreeCheck(graph);
        printDivider();
    }

    if (doCycle) {
        runCycleCheck(graph);
        printDivider();
    }

    if (doBipartite) {
        runBipartiteCheck(graph, bipartite);
        printDivider();
    }

    if (doTraversal) {
        runTraversals(graph);
        printDivider();
    }

    if (doHall) {
        runHallCheck(graph, bipartite);
        printDivider();
    }

    if (doEuler) {
        runEulerCheck(graph);
        printDivider();
    }

    if (doDot) {
        runGraphvizExport(graph);
        printDivider();
    }

    if (doShortest) {
        runShortestPath(graph);
        printDivider();
    }

    if (doTopo) {
        runTopologicalSort(graph);
        printDivider();
    }

    if (doSCC) {
        runSCCKosaraju(graph);
        printDivider();
    }
}
