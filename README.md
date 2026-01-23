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
  - [`Graph_Implementation_Selector.cpp`](src/Graph_Implementation_Selector.cpp) — Handles graph creation and implementation selection  
  - [`Graph_Implementation_Selector.h`](src/Graph_Implementation_Selector.h) — Declarations for selector functions and adapters  
  - [`Matrix_Implementation_Graph.cpp`](src/Matrix_Implementation_Graph.cpp) — Matrix graph implementation  
  - [`Matrix_Implementation_Graph.h`](src/Matrix_Implementation_Graph.h) — Matrix graph declarations  
  - [`List_Implementation_Graph.cpp`](src/List_Implementation_Graph.cpp) — List graph implementation  
  - [`List_Implementation_Graph.h`](src/List_Implementation_Graph.h) — List graph declarations  

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
5
Enter number of edges: 
4
Is the graph directed? (y/n): 
n
Is the graph dense? (y/n): 
n
Is the graph dynamic (frequent insert/delete)? (y/n): 
n
Using adjacency list
Enter edges (u v):
0 1
1 2
2 3
3 4

Adjacency List:
0: 1 -> NULL
1: 2 -> 0 -> NULL
2: 3 -> 1 -> NULL
3: 4 -> 2 -> NULL
4: 3 -> NULL
```
