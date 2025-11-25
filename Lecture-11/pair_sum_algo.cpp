#include<iostream>
#include<vector>
using namespace std;
vector<int> pair_sum(vector<int> nums,int target){
  vector<int> ans;
  int n=nums.size();
  int i=0,j=n-1;
  while(i<j){
    int pair_sum=nums[i]+nums[j];
    if(pair_sum> target){
      j--;
    }
      else if(pair_sum<target){
        i++;
      }
        else{
          ans.push_back(i);
          ans.push_back(j);
          return ans;
    }
  }
  return ans;
}
int main(){
  vector<int> nums={2,3,4,5};
  int target=9;
  vector<int> ans=pair_sum(nums,target);
  cout<<ans[0]<<" , "<<ans[1];
  cout<<endl;
  return(0);
}