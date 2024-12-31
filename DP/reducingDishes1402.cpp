class Solution {
    private:
    int solve(int i,int t,vector<int> &satisfaction){
        int n=satisfaction.size();
        if(i>=n){
            return 0;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int include=satisfaction[i]*t+solve(i+1,t+1,satisfaction);
        int exclude=solve(i+1,t,satisfaction);
        return dp[i][t]=max(include,exclude);
    }
public:
    int dp[501][501];
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,1,satisfaction);
    }
};
