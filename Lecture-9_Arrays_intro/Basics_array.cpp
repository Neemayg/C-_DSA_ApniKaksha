#include<iostream>
using namespace std;
void printArray(int arr[],int size){
  cout<<"Printing strating"<<endl;
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<"Printing Done"<<endl;
} 
int main(){

  int arr[15];

  cout<<"Value at 0 index is: "<<arr[0]<<endl;
  cout<<"Value at 1 index is: "<<arr[1]<<endl;

  cout<<"Hello World"<<endl;

  int arr1[10]={2,4,6,8,10};
  int size=10;
  printArray(arr1,10);

  int arr1size=sizeof(arr1)/sizeof(int);
  cout<<"Size of the arr1 is: " << arr1size <<endl;




  return 0;
}