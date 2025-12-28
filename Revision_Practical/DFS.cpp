#include <iostream>
using namespace std;

int G[10][10], visited[10], n;

void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(G[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
        visited[i] = 0;
    }

    cout << "DFS Traversal: ";
    DFS(0);

    return 0;
}


