#include<iostream>
#include <climits>
using namespace std;
int Max_num(int arr[],int n){

  int max=INT_MIN;
  for(int i=0;i<n;i++){
    if(arr[i]>max){
      max=arr[i];
    }
  }
  return max;

}
int Min_num(int arr[],int n){

  int min=INT_MAX;
  for(int i=0;i<n;i++){
    if(arr[i]<min){
      min=arr[i];
    }
  }
  return min;

}
int main(){
  int size;
  cout<<"Enter the size of the array you want: "<<" ";
  cin>>size;
  int arr[100];
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  cout<<"Maximum number is: "<<Max_num(arr,size)<<endl;
  cout<<"Minimum number is: "<<Min_num(arr,size)<<endl;
  return 0;
}