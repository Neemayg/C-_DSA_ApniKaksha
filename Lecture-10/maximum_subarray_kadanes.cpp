#include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"Enter number of elements you want in array: ";
  cin>>n;
  cout<<"Enter the "<< n <<" elemnts in the array: ";
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int i;
  int current_sum=0,max_sum=INT_MIN;
  for(i=0;i<n;i++){
    current_sum=arr[i];
    max_sum=max(current_sum,max_sum);
    if(current_sum<0){
      current_sum=0;
    }
  }
  cout<<"Maximum sum of this subarray is: "<<current_sum<<endl;
    return(0);
}