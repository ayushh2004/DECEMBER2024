class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> answer;
        int subsets=(1<<n);
        for(int binaryGenerated=0;binaryGenerated<subsets;binaryGenerated++){
            vector<int> subsetVector;
            for(int i=0;i<n;i++){
                if((1<<i)&binaryGenerated) subsetVector.push_back(nums[i]);
            }
            answer.push_back(subsetVector);
        }
        return answer;
    }
};
