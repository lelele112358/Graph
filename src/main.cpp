//***************************************************************
// File: main.cpp
// Description:
//   Entry point for the Graph project.
//
//   Responsibilities:
//     - Create a graph object using GraphFactory
//     - Delegate all user interaction to Graph_CLI
//     - Clean up allocated memory
//
// Notes:
//   - Keeping main.cpp small makes the project easier to maintain
//***************************************************************

#include "GraphFactory.h"
#include "Graph_CLI.h"

#include <iostream>
using namespace std;

// Function: main
// Parameters:
// None
// Output:
// Creates a graph and runs the CLI controller
int main() {
    IGraph* graph = selectAndCreateGraph();

    if (graph == NULL) {
        cout << "Failed to create graph." << endl;
        return 1;
    }

    runGraphCLI(*graph);

    delete graph;
    return 0;
}
