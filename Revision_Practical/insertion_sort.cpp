#include<iostream>
using namespace std;
int main(){
  int i,n,curr,prev,arr[100];
  cout<<"Enter number of elements to sort by inserted array selection: ";
  cin>>n;
  cout<<"Enter the elements which you want to insert: "<<endl;
  for(i=0;i<n;i++){
    cin>>arr[i];
  }
  for(i=1;i<n;i++){
    curr=arr[i];
    prev=i-1;
  
  while (prev>=0 && arr[prev]>curr){
    arr[prev + 1] = arr[prev];
    prev--;
    }
    arr[prev+1]=curr;
  }
    cout<<"Sorted array"<<" ";
    for(i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}