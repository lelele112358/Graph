# Graph

![C++](https://img.shields.io/badge/Language-C++17-blue)
![Build](https://img.shields.io/badge/Build-Make-green)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

## Overview
This project is a C++ graph algorithms library built to explore both graph theory concepts and clean software design.
It supports multiple graph representations and a collection of classical graph algorithms, organized with clear abstractions and modular files.
The goal is to make it easy to add new algorithms, switch graph representations, and reuse code without rewriting existing logic.

---

## Features

### Graph Representations
- Adjacency List
  - Efficient for sparse graphs
  - Fast neighbor iteration
- Adjacency Matrix
  - Efficient for dense graphs
  - Constant-time edge existence checks
### Graph Types
- Directed graphs
- Undirected graphs
### Implemented Algorithms
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Cycle detection (directed and undirected)
- Connectivity check
- Tree check (connected + acyclic + undirected)
- Bipartite graph check with partitions
- Hall’s Marriage Theorem (naive subset check, small graphs)
- Euler path / Euler circuit existence
- Shortest path (unweighted) using BFS with path reconstruction
- Topological sort (directed acyclic graphs)
- Strongly Connected Components (SCC) using Kosaraju’s algorithm
### Visualization
- Graphviz (.dot) export
  - Export graphs for visualization
  - Compatible with Graphviz tools (dot, neato, etc.)

---

## Technologies

- **Language:** C++
- **Compiler:** g++ (C++17)
- **Build Tool:** Make

---

## Project Structure

```text
.
├── README.md
├── .gitignore
├── Makefile
├── include
│   ├── IGraph.h
│   ├── GraphFactory.h
│   ├── Graph_CLI.h
│   ├── Matrix_Implementation_Graph.h
│   ├── List_Implementation_Graph.h
│   ├── BFS_Traversal.h
│   ├── DFS_Traversal.h
│   ├── Graph_Connectivity.h
│   ├── Cycle_Detection.h
│   ├── Graph_Tree.h
│   ├── Graph_Bipartite.h
│   ├── Halls_Marriage_Theorem.h
│   ├── Euler_Theorem.h
│   ├── Shortest_Path_Unweighted.h
│   ├── Topological_Sort.h
│   ├── SCC_Kosaraju.h
│   └── Graphviz_Export.h
└── src
    ├── main.cpp
    ├── GraphFactory.cpp
    ├── Graph_CLI.cpp
    ├── Matrix_Implementation_Graph.cpp
    ├── List_Implementation_Graph.cpp
    ├── BFS_Traversal.cpp
    ├── DFS_Traversal.cpp
    ├── Graph_Connectivity.cpp
    ├── Cycle_Detection.cpp
    ├── Graph_Tree.cpp
    ├── Graph_Bipartite.cpp
    ├── Halls_Marriage_Theorem.cpp
    ├── Euler_Theorem.cpp
    ├── Shortest_Path_Unweighted.cpp
    ├── Topological_Sort.cpp
    ├── SCC_Kosaraju.cpp
    └── Graphviz_Export.cpp

```

## Build & Run

### Using Make

1. Open a terminal and navigate to the project directory:

```bash
cd Graph
```

2. Build the project:

```bash
make
```

3. Run the program:

```bash
./graph
```

4. Clean compiled files:

```bash
make clean
```

Graphviz Usage (Optional)
To visualize a graph:
1. Export a .dot file from the program
2. Render it using Graphviz:

```bash
dot -Tpng graph.dot -o graph.png
```

## Example Run

```yaml
Enter number of vertices: 10
Enter number of edges: 15
Is the graph directed? (y/n): n
Is the graph dense? (y/n): y
Is the graph dynamic? (y/n): n
Using adjacency matrix
Enter edges (u v):
0 1
0 4
0 5
1 2
1 6
2 3
2 7
3 4
3 8
4 9
5 7
5 8
6 8
6 9
7 9
-----------------------------
Adjacency Matrix:
0 1 0 0 1 1 0 0 0 0 
1 0 1 0 0 0 1 0 0 0 
0 1 0 1 0 0 0 1 0 0 
0 0 1 0 1 0 0 0 1 0 
1 0 0 1 0 0 0 0 0 1 
1 0 0 0 0 0 0 1 1 0 
0 1 0 0 0 0 0 0 1 1 
0 0 1 0 0 1 0 0 0 1 
0 0 0 1 0 1 1 0 0 0 
0 0 0 0 1 0 1 1 0 0 
-----------------------------
Check if graph is a tree? (y/n): y
Check if graph has cycles? (y/n): y
Check if graph is bipartite? (y/n): y
Perform BFS/DFS traversals? (y/n): y
Check Hall's Marriage Theorem? (y/n): y
Check Euler path/circuit existence? (y/n): y
Export graph to Graphviz (.dot)? (y/n): y
Find shortest path using BFS? (y/n): y
Perform topological sort? (y/n): y
Find strongly connected components (SCC)? (y/n): y
Check Dirac/Ore Hamiltonian theorems? (y/n): y
-----------------------------
Graph is NOT a tree.
-----------------------------
Graph contains a cycle.
-----------------------------
Graph is NOT bipartite.
-----------------------------
Enter starting vertex for BFS/DFS: 3
BFS Traversal starting from vertex 3: 3 2 4 8 1 7 0 9 5 6 
DFS Traversal starting from vertex 3: 3 2 1 0 4 9 6 8 5 7 
-----------------------------
Cannot apply Hall's theorem: graph not bipartite.
-----------------------------
Graph does NOT have an Euler path or Euler circuit.
-----------------------------
Enter output DOT filename (example: graph.dot): asdf.dot
DOT file saved: asdf.dot
Tip: dot -Tpng asdf.dot -o graph.png
-----------------------------
Enter start vertex: 3
Enter target vertex: 5
Shortest distance from 3 to 5 is 2 edges.
Path: 3 -> 8 -> 5
-----------------------------
Topological sort not possible (graph is undirected or contains a cycle).
-----------------------------
SCC is mainly for directed graphs (undirected SCC = connected components).
Strongly Connected Components (1):
SCC 0: 0 1 2 3 4 9 6 8 5 7 
-----------------------------
Hamiltonian Theorem Check (Dirac + Ore)
Dirac's Theorem: FAILED
  Minimum degree = 3
Ore's Theorem: FAILED
  Ore violations = 30
Result: Not guaranteed by Dirac or Ore.
-----------------------------
```

## Notes
- The CLI is intentionally separated from algorithm logic
- Algorithms work with any graph implementing IGraph
- Visualization files (.dot, .png) are ignored by Git
- The project is designed for experimentation and extension