#include <bits/stdc++.h>
using namespace std;

void calculateLongestIncreasingSubsequence(vector<int> &nums){
    int n=nums.size();
    int maximumLIS=-1e9;
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i-1;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        maximumLIS=max(maximumLIS,dp[i]);
    }
    cout<<"Longest Increasing Subsequence is of length "<<maximumLIS<<endl;
} //TC->0(N^2 QUADRATIC)
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    calculateLongestIncreasingSubsequence(nums);
    return 0;
}
