#include <bits/stdc++.h>
using namespace std;

void printLongestIncreasingSubsequence(vector<int> &nums){
    int n=nums.size();
    int maximumLIS=-1e9;
    int lastIndex=0;
    vector<int> dp(n,1), hash(n);
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int j=0;j<=i-1;j++){
            if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
                hash[i]=j;
            }
        }
        if(dp[i]>maximumLIS){
            maximumLIS=dp[i];
            lastIndex=i;
        }
    }
    cout<<"Longest Increasing Subsequence is of length "<<maximumLIS<<endl;
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    cout<<"Longest Increasing Subsequence ";
    for(auto it:temp){
        cout<<it<<" ";
    }
} //TC->0(N^2 QUADRATIC)
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    printLongestIncreasingSubsequence(nums);
    return 0;
}
