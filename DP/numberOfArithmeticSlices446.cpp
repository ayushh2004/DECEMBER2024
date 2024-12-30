class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result=0;
        int n=nums.size();
        unordered_map<long,int> mp[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff=(long)nums[i]-nums[j];
                auto it=mp[j].find(diff);
                int countAtJ=(it==end(mp[j])? 0:it->second);
                mp[i][diff]+=countAtJ+1;
                result+=countAtJ;
            }
        }
        return result;
    }
};
