#include <iostream>
#include <vector>
using namespace std;

class graph {
    int V;
    vector<vector<int>> adj;

public:
    graph(int vertices) {
        V = vertices;
        adj = vector<vector<int>>(V);
    }

    void add_edge(int from, int to) {
        if (to >= adj.size())
            return;
        bool found = false;
        for (int i = 0; i < adj[from].size(); i++) {
            if (adj[from][i] == to) {
                found = true;
                break;
            }
        }
        if (!found)
            adj[from].push_back(to);
    }

    void print_neighbors(int vertex = -1) {
        for (int i = 0; i < V; i++) {
            if (vertex < 0 || i == vertex) {
                cout << (char)(i + 'A') << ":[";
                for (int j = 0; j < adj[i].size(); j++)
                    cout << (char)(adj[i][j] + 'A') << ((j == (adj[i].size() - 1)) ? "" : ",");
                cout << "]\n";
            }
        }
    }
};

/*
    A: [B, D]
    B: [C]
    C: []
    D: [C, E]
    E: []
*/
int main() {
    graph *G = new graph(5);
    G->add_edge(0, 1);
    G->add_edge(0, 3);
    G->add_edge(1, 2);
    G->add_edge(3, 2);
    G->add_edge(3, 4);

    G->print_neighbors();
    return 0;
}