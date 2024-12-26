class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        return solve(nums,0,0,target);
    }
private:
    int solve(vector<int> &nums,int ind,int currSum,int target){
        if(ind==nums.size()){
            if(currSum==target){
                return 1;
            }else{
                return 0;
            }
        }
        int plus=solve(nums,ind+1,currSum+nums[ind],target);
        int minus=solve(nums,ind+1,currSum-nums[ind],target);
        return minus+plus;
    }
};
