#include<iostream>
#include<queue>
using namespace std;
int main(){
  int G[10][10],visited[10],i,j,n,start;
  queue<int> q;
  cout<<"Enter no of vertices: ";
  cin>>n ;
  cout<<"Enter the adjacent matrics: ";
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin>>G[i][j];
    }
    visited[i]=0;
  }
  cout<<"Enter the starting vertex: ";
  cin>>start;
  q.push(start);
  visited[start]=1;
  cout<<"BFS Traversal: ";
  while(!q.empty()){
    int curr =q.front();
    q.pop();
    cout<<curr<<" ";
    for(i=0;i<n;i++){
      if(G[curr][i]==1 && visited[i]==0){
        q.push(i);
        visited[i]=1;
      }
    }
  }
  return 0;
}
