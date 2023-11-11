#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class graph {
    int V;
    vector<vector<int>> adj;

public:
    int get_V() {
        return V;
    }

    graph(int vertices) {
        V = vertices;
        adj = vector<vector<int>>(vertices);
    }

    void add_edge(int start, int end, bool undirected = false) {
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

        if (undirected) {
            found = false;
            for (int i = 0; i < adj[end].size(); i++) {
                if (adj[end][i] == start) {
                    found = true;
                    break;
                }
            }
            if (!found)
                adj[end].push_back(start);
        }
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

    void BFS_traversal(int start_node) {
        queue<int> Q;
        int cur = start_node;

        if (cur > V)
            return;

        vector<bool> visited(V, false);
        Q.push(cur);
        visited[cur] = true;
        while(!Q.empty()) {
            cur = Q.front();
            cout << (char)(cur + 'A') << " ";
            Q.pop();
            for (int index = 0; index < adj[cur].size(); index++) {
                int nbor = adj[cur][index];
                if (!visited[nbor])
                    Q.push(adj[cur][index]);
                    visited[nbor] = true;
            }
        }
    }

    void DFS_traversal(int start_node, vector<bool>& visited) {
        // graph *G = this;
        int cur = 0;

        if (start_node >= 0)
            cur = start_node;

        visited[cur] = true;
        cout << (char)(cur + 'A') << " ";
        // cout << cur << " ";
        // for (int nbor: G->adj[cur]){
            for (int nbor: adj[cur]){
            if (!visited[nbor])
                DFS_traversal(nbor, visited);
        }
    }

    void DFS_traversal_stack(int start_node) {
        int cur = start_node;
        vector<bool> visited(V, false);
        stack<int> S;
        S.push(cur);
        while (!S.empty()) {
            cur = S.top();
            S.pop();
            if (!visited[cur]) {
                cout << (char)(cur + 'A') << " ";
                // cout << cur << " ";
                visited[cur] = true;
            }
            int nbor;
            // If looping forward through the neighbors they will be printed in reverse
            // So, to print in order of occurence, loop through the neighbors in reverse
            // Either way, the traversal is DFS and correct
            for (int i = adj[cur].size() - 1; i >= 0; i--) {
                nbor = adj[cur][i];
                if (!visited[nbor])
                    S.push(nbor);
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

        A
       / \
      B   D
      | / |
      C   E

BFS Traversal: A B D C E
*/
int main() {
    graph *G = new graph(5);
    G->add_edge(0, 1);
    G->add_edge(0, 3);
    G->add_edge(1, 2);
    G->add_edge(3, 2);
    G->add_edge(3, 4);

    G->print_adj();

    cout << "BFS_traversal:\t";
    G->BFS_traversal(0);

    cout << "\nDFS_traversal:\t";
    vector<bool> visited(G->get_V(), false);
    G->DFS_traversal(0, visited);

    cout << "\nDFS_traversal_stack:\t";
    G->DFS_traversal_stack(0);

    return 0;
}