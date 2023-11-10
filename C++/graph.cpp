#include <iostream>
#include <vector>
using namespace std;

class graph {
    int V;
    vector<vector<int>> adj;

public:
    graph(int vertices) {
        V = vertices;
        adj = vector<vector<int>>(vertices);
    }

    void add_edge(int start, int end) {
        if (start >= V || end >= V)
            return;
        bool found = false;
        for (int i = 0; i < adj[start].size(); i++) {
            if (adj[start][i] == end) {
                found = true;
                break;
            }
        }
        if (!found)
            adj[start].push_back(end);
    }

    void print_adj(int start = -1) {
        for (int i = 0; i < V; i++) {
            if (start < 0 || start == i) {
                cout << (char)(i + 'A') << ":[";
                for (int j = 0; j < adj[i].size(); j++)
                    cout << (char)(adj[i][j] + 'A') << (j == (adj[i].size() - 1)? "" : ",");
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

    G->print_adj(0);
    G->print_adj(3);

    return 0;
}