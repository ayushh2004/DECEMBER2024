class Solution {
public:
    const int M=1e9+7;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,0);
        dp[0]=1;
        for(int i=1;i<=high;i++){
            if(i-zero>=0){
                dp[i]=(dp[i]+dp[i-zero])%M;
            }
            if(i-one>=0){
                dp[i]=(dp[i]+dp[i-one])%M;
            }
        }
        int total=0;
        for(int i=low;i<=high;i++){
            total=(total+dp[i])%M;
        }
        return total%M;
    }
};
