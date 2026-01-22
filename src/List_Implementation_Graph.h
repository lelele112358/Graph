#ifndef LIST_IMPLEMENTATION_GRAPH_H
#define LIST_IMPLEMENTATION_GRAPH_H

#include <vector>
using namespace std;

class GraphList {
private:
    int V;
    vector<vector<int>> adjList;

public:
    GraphList(int vertices);
    void addEdge(int u, int v);
    void display() const;
};

#endif
