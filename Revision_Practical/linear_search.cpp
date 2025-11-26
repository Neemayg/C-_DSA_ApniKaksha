#include <iostream>
using namespace std;
int main(){
int arr[100],item,n,i,found=0;
cout<<"Enter no of elements you want to enter: ";
cin>>n;
cout<<"Enter the elements: "<<endl;
for(i=0;i<n;i++){
  cin>>arr[i];
}
cout<<"Enter the element you ewant to search: ";
cin>>item;
for(i=0;i<n;i++){
  if(item==arr[i]){
    cout<<"Element is present in the array at index: "<<i<<endl;
    found=1;
  }
}
if (!found){
  cout<<"No element found at any index"<<endl;
}
return 0;
}