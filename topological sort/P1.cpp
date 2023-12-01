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

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* top = nullptr;

void push(int x) {
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == nullptr) {
        cout << "Stack empty";
        return -1;
    } else {
        node* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }
}

bool isEmpty() {
    return top == nullptr;
}

void Visited(int v, bool Array[], list<Edge> Graph[]) {
    Array[v] = true;

    for (Edge e : Graph[v]) {
        int adjacentVertex = e.dis;
        if (!Array[adjacentVertex]) {
            Visited(adjacentVertex, Array, Graph);
        }
    }

    push(v);
}

void topoSort(list<Edge> Graph[], int size, int start) {
    bool* Array = new bool[size];
    for (int i = 0; i < size; i++) {
        Array[i] = false;
    }

    Visited(start, Array, Graph);

    for (int i = 0; i < size; i++) {
        if (!Array[i]) {
            Visited(i, Array, Graph);
        }
    }

    cout << "Topological Sort: ";
    while (!isEmpty()) {
        cout << pop() << " ";
    }

    delete[] Array;
}

int main() {
    int v = 6;


    list<Edge> Graph[v];
    Graph[5].push_back(Edge(0));
    Graph[5].push_back(Edge(2));

    Graph[4].push_back(Edge(0));
    Graph[4].push_back(Edge(1));

    Graph[2].push_back(Edge(3));
    Graph[3].push_back(Edge(1));

    int start = 4;
    topoSort(Graph, v, start);

    return 0;
}
