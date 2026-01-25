//***************************************************************
// File: Graph_CLI.h
// Description:
//   Declares the Command Line Interface (CLI) controller for the
//   Graph project.
//
//   This module handles:
//     - printing menus / prompts
//     - reading user choices
//     - calling algorithm modules
//     - formatting output for the console
//
// Notes:
//   - Keeps main.cpp small and clean
//   - Keeps algorithms in their own modules (no UI mixed in)
//***************************************************************

#ifndef GRAPH_CLI_H
#define GRAPH_CLI_H

#include "IGraph.h"

// Function: runGraphCLI
// Parameters:
// IGraph& graph - reference to a graph object created by GraphFactory
// Output:
// Runs the interactive menu that lets the user run graph operations
void runGraphCLI(IGraph& graph);

#endif
