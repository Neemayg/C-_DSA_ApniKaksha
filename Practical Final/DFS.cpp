#include <iostream>
using namespace std;

int G[10][10],visited[10],n,i,j;
void DFS(int i){
  cout<< i <<" ";
  visited[i]=0;

  for(j=0;j<n;j++){
    if(G[i][j]==1 && (!visited[j])){
      DFS(j);
    }
  }
}