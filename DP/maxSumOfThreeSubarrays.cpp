class Solution {
    int t[20001][4];
    private:
    int helper(vector<int>& subarray,int count,int i,int k){
        if(count==0) return 0;
        if(i>=subarray.size()) return INT_MIN;
        if(t[i][count]!=-1) return t[i][count];
        int take=subarray[i]+helper(subarray,count-1,i+k,k);
        int nottake=helper(subarray,count,i+1,k);
        return t[i][count]=max(take,nottake);
    }
    void solve(vector<int>& subarray,int k,int count,int i,vector<int> &result){
        if(count==0 || i>=subarray.size()) return;
        int take_i=subarray[i]+helper(subarray,count-1,i+k,k);
        int nottake_i=helper(subarray,count,i+1,k);
        if(take_i>=nottake_i){
            result.push_back(i);
            solve(subarray,k,count-1,i+k,result);
        }else{
            solve(subarray,k,count,i+1,result);
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t,-1,sizeof(t));
        vector<int> subarray;
        int i=0,j=0;
        int windowSum=0;

        while(j<nums.size()){
            windowSum+=nums[j];
            if(j-i+1==k){
                subarray.push_back(windowSum);
                windowSum-=nums[i];
                i++;
            }
            j++;
        }

        vector<int> result;
        solve(subarray,k,3,0,result);
        return result;
    }
};
