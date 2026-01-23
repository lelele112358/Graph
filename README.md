# Graph

![C++](https://img.shields.io/badge/Language-C++17-blue) ![Build](https://img.shields.io/badge/Build-Make-green) ![License](https://img.shields.io/badge/License-MIT-lightgrey)

A C++ project implementing graph data structures, designed for academic purposes and experimentation with graph algorithms.

---

## 📌 Features

- Implements graphs using **adjacency lists** and **adjacency matrices**  
- Supports **directed and undirected graphs**  
- Dynamic insertion of vertices and edges  
- Modular design for easy extension with graph algorithms  

---

## 🛠 Technologies

- **Language:** C++  
- **Compiler:** g++ (C++17 standard)  
- **Build Tool:** Make  

---

## 📂 Project Structure

- `README.md` — Project overview and instructions  
- `.gitignore` — Specifies files to ignore in Git  
- `Makefile` — Build and clean commands  
- `src/` — Source code  
  - [`main.cpp`](src/main.cpp) — Entry point  
  - [`Matrix_Implementation_Graph.cpp`](src/Matrix_Implementation_Graph.cpp) — Matrix graph implementation  
  - [`Matrix_Implementation_Graph.h`](src/Matrix_Implementation_Graph.h) — Matrix graph declarations  
  - [`List_Implementation_Graph.cpp`](src/List_Implementation_Graph.cpp) — List graph implementation  
  - [`List_Implementation_Graph.h`](src/List_Implementation_Graph.h) — List graph declarations  
  - [`GraphFactory.cpp`](src/GraphFactory.cpp) — Factory for creating graph objects  
  - [`GraphFactory.h`](src/GraphFactory.h) — Declarations for the graph factory  
  - [`Graph_Bipartite.cpp`](src/Graph_Bipartite.cpp) — Bipartite graph checking implementation  
  - [`Graph_Bipartite.h`](src/Graph_Bipartite.h) — Declarations for bipartite checking  
  - [`IGraph.h`](src/IGraph.h) — Interface for graph implementations  


> Total of 7 files. Clickable links work on GitHub to open the source code directly.

---

## ⚙️ Build & Run

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

## 📝 Example Run

```yaml
Enter number of vertices: 
10
Enter number of edges: 
15
Is the graph directed? (y/n): 
n
Is the graph dense? (y/n): 
n
Is the graph dynamic? (y/n): 
n
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
The graph is NOT bipartite.
```

```yaml
Enter number of vertices: 
10
Enter number of edges: 
15
Is the graph directed? (y/n): 
n
Is the graph dense? (y/n): 
y
Is the graph dynamic? (y/n): 
n
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
The graph is NOT bipartite.
```
