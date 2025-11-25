#include<iostream>
using namespace std;

bool prime_number(int n){
  if(n<=1){
    return false;
  }
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
int main(){
  int n;
  cout<<"Enter a number to check if it is prime or not: ";
  cin>>n;
  if(prime_number(n)){
    cout<<"Prime number"<<endl;
  }else{
      cout<<"Not a prime number"<<endl;
    }
  return(0);
}