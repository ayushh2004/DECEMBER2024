class Solution {
    private:
    int solve(int i,vector<int>& days, vector<int>& cost){
        int n=days.size();
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int oneDayCost=cost[0]+solve(i+1,days,cost);
        int max7days=days[i]+7;
        int j=i;
        while(j<n && days[j]<max7days){
            j++;
        }
        int sevenDayCost=cost[1]+solve(j,days,cost);
        int max15days=days[i]+30;
        j=i;
        while(j<n && days[j]<max15days){
            j++;
        }
        int fifteenDayCost=cost[2]+solve(j,days,cost);
        return t[i]=min({oneDayCost,sevenDayCost,fifteenDayCost});
    }
public:
    int t[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(t,-1,sizeof(t));
        return solve(0,days,costs);
    }
};




class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        unordered_set<int> st(begin(days),end(days));
        int lastDay=days.back();
        vector<int> dp(366);
        dp[0]=0;
        for(int i=1;i<=lastDay;i++){
            if(st.find(i)==st.end()){
                dp[i]=dp[i-1];
                continue;
            }
            dp[i]=INT_MAX;
            int c1=costs[0]+dp[max(i-1,0)];
            int c2=costs[1]+dp[max(i-7,0)];
            int c3=costs[2]+dp[max(i-30,0)];
            dp[i]=min({c1,c2,c3});
        }
        return dp[lastDay];
    }
};
