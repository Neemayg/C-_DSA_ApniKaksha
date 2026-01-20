#include<iostream>
using namespace std;
int main(){

  int size,arr[100],sum;
  cout<<"Enter the number of elements you want in the array: ";
  cin>>size;
  cout<<"Enter the elements: "<<endl;
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  for(int i=0;i<size;i++){
    sum+=arr[i];
  }
  cout<<"Sum of the elemenst entered in the array are: "<<sum <<endl;
  return 0;
}