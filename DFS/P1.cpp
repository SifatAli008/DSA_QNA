//DFS
// Created by Sifat Ali on 11/27/2023.
//
#include <iostream>
#include <list>

using namespace std;

class Edge {
public:
    int dis;
    Edge(int dis) {
        this->dis = dis;
    }
};

void check(int v, bool visited[], list<Edge> Graph[]) {
    visited[v] = true;
    cout << v << " ";

    for (Edge e : Graph[v]) {
        int adjacentVertex = e.dis;
        if (!visited[adjacentVertex]) {
            check(adjacentVertex, visited, Graph);
        }
    }
}

void DFS(list<Edge> Graph[], int size, int start) {
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }
    check(start, visited, Graph);

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            check(i, visited, Graph);
        }
    }
}

int main() {
    int v = 4;

    list<Edge> Graph[v];
    Graph[0].push_back(Edge(1));
    Graph[0].push_back(Edge(2));

    Graph[1].push_back(Edge(2));

    Graph[2].push_back(Edge(0));
    Graph[2].push_back(Edge(3));

    Graph[3].push_back(Edge(3));

    int start = 2;
    cout << "DFS : ";
    DFS(Graph, v, start);
}
