#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int l = nums.size();
    int dp[l];
    if(l == 0)  return 0;
    dp[0] = nums[0];
    int res = nums[0];
    for(int i=1; i<l; i++){
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        res = max(res, dp[i]);
    }
    return res; 
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}