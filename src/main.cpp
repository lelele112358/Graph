#include <iostream>
#include "Matrix_Implementation_Graph.h"
#include "List_Implementation_Graph.h"

using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    GraphMatrix matrixGraph(V);
    GraphList listGraph(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        matrixGraph.addEdge(u, v);
        listGraph.addEdge(u, v);
    }

    matrixGraph.display();
    listGraph.display();

    return 0;
}
