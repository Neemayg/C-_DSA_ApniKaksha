#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int n, G[10][10];
    int visited[10] = {0};
    int i, j, u, v, min;
    int edges = 0, total_cost = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (enter 99999 for infinity):\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    visited[0] = 1; // Start from first node

    cout << "\nMinimum Spanning Tree Edges:\n";

    while (edges < n - 1) {
        min = INF;
        u = 0;
        v = 0;

        // Find smallest edge connecting visited to unvisited
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && G[i][j] < min) {
                        min = G[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " : " << min << endl;

        total_cost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "Total Cost of MST: " << total_cost << endl;

    return 0;
}
