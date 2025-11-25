#include<iostream>
using namespace std;
int prime_number(int n){
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      break;
    }
  }
}
int main(){
  return(0);
}