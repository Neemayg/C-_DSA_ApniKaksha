#include <iostream>
using namespace std;

int G[10][10], visited[10], n, i, j;

void DFS(int i) {
    cout << i << " ";
    visited[i] = 1;  

    for (j = 0; j < n; j++) {
        if (G[i][j] == 1 && visited[j] == 0) {  
            DFS(j);
        }
    }
}

int main() {
    cout << "Enter number of users you want to enter: ";
    cin >> n;

    cout << "Enter adjacency matrix for the social media app:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS Traversal: ";
    DFS(0);
    cout << endl;

    return 0;
}
