//***************************************************************
// File: main.cpp
// Description:
//   Main program to create a graph via user input, display it,
//   check tree, cycles, bipartite, BFS/DFS, and Hall's theorem.
//
// Notes:
//   - User chooses which operations to run
//***************************************************************

#include "GraphFactory.h"
#include "Graph_Bipartite.h"
#include "Graph_Tree.h"
#include "Graph_Connectivity.h"
#include "Cycle_Detection.h"
#include "BFS_Traversal.h"
#include "DFS_Traversal.h"
#include "Halls_Marriage_Theorem.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {
    IGraph* graph = selectAndCreateGraph();

    cout << "-----------------------------" << endl;
    graph->display();
    cout << "-----------------------------" << endl;

    char doTree, doCycle, doBipartite, doTraversal, doHall;
    cout << "Check if graph is a tree? (y/n): "; cin >> doTree;
    cout << "Check if graph has cycles? (y/n): "; cin >> doCycle;
    cout << "Check if graph is bipartite? (y/n): "; cin >> doBipartite;
    cout << "Perform BFS/DFS traversals? (y/n): "; cin >> doTraversal;
    cout << "Check Hall's Marriage Theorem? (y/n): "; cin >> doHall;
    cout << "-----------------------------" << endl;

    bool bipartite = false;

    if (doTree == 'y' || doTree == 'Y') {
        if (isTree(*graph)) {
            cout << "Graph is a tree. It's acyclic and bipartite." << endl;
        } else {
            cout << "Graph is NOT a tree." << endl;
        }
        cout << "-----------------------------" << endl;
    }

    if ((doCycle == 'y' || doCycle == 'Y') && !(doTree == 'y' || doTree == 'Y')) {
        if (hasCycle(*graph)) {
            cout << "Graph contains a cycle." << endl;
        } else {
            cout << "Graph does NOT contain a cycle." << endl;
        }
        cout << "-----------------------------" << endl;
    }

    if (doBipartite == 'y' || doBipartite == 'Y') {
        bipartite = isBipartite(*graph);
        cout << (bipartite ? "Graph is bipartite." : "Graph is NOT bipartite.") << endl;
        cout << "-----------------------------" << endl;
    }

    if (doTraversal == 'y' || doTraversal == 'Y') {
        BFS(*graph, 0);
        DFS(*graph, 0);
        cout << "-----------------------------" << endl;
    }

    if ((doHall == 'y' || doHall == 'Y') && bipartite) {
        vector<int> left = getLeftPartition(*graph);
        vector<int> right = getRightPartition(*graph);

        if (hasPerfectMatchingHall(*graph, left, right)) {
            cout << "Perfect matching exists." << endl;
        } else {
            cout << "No perfect matching exists." << endl;
        }
        cout << "-----------------------------" << endl;
    } else if ((doHall == 'y' || doHall == 'Y') && !bipartite) {
        cout << "Cannot apply Hall's theorem: graph not bipartite." << endl;
        cout << "-----------------------------" << endl;
    }

    delete graph;
    return 0;
}
