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

- Two graph representations:
  - Adjacency **List** (best for sparse graphs)
  - Adjacency **Matrix** (best for dense graphs / fast edge checks)
- Directed and undirected graphs
- Graph algorithms included:
  - BFS traversal
  - DFS traversal
  - Cycle detection (directed + undirected)
  - Connectivity check
  - Tree check (connected + acyclic + undirected)
  - Bipartite check + partitions
  - Hall’s Marriage Theorem (naive subset check for small graphs)
  - Euler path/circuit existence check

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
│   ├── Matrix_Implementation_Graph.h
│   ├── List_Implementation_Graph.h
│   ├── BFS_Traversal.h
│   ├── DFS_Traversal.h
│   ├── Graph_Connectivity.h
│   ├── Cycle_Detection.h
│   ├── Graph_Tree.h
│   ├── Graph_Bipartite.h
│   ├── Halls_Marriage_Theorem.h
│   └── Euler_Theorem.h
└── src
    ├── main.cpp
    ├── GraphFactory.cpp
    ├── Matrix_Implementation_Graph.cpp
    ├── List_Implementation_Graph.cpp
    ├── BFS_Traversal.cpp
    ├── DFS_Traversal.cpp
    ├── Graph_Connectivity.cpp
    ├── Cycle_Detection.cpp
    ├── Graph_Tree.cpp
    ├── Graph_Bipartite.cpp
    ├── Halls_Marriage_Theorem.cpp
    └── Euler_Theorem.cpp

---

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
```

```yaml
Enter number of vertices: 10
Enter number of edges: 15
Is the graph directed? (y/n): n
Is the graph dense? (y/n): n
Is the graph dynamic? (y/n): n
Using adjacency list
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
Adjacency List:
0: 1 -> 4 -> 5 -> NULL
1: 0 -> 2 -> 6 -> NULL
2: 1 -> 3 -> 7 -> NULL
3: 2 -> 4 -> 8 -> NULL
4: 0 -> 3 -> 9 -> NULL
5: 0 -> 7 -> 8 -> NULL
6: 1 -> 8 -> 9 -> NULL
7: 2 -> 5 -> 9 -> NULL
8: 3 -> 5 -> 6 -> NULL
9: 4 -> 6 -> 7 -> NULL
-----------------------------
Check if graph is a tree? (y/n): y
Check if graph has cycles? (y/n): y
Check if graph is bipartite? (y/n): y
Perform BFS/DFS traversals? (y/n): y
Check Hall's Marriage Theorem? (y/n): y
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
```
