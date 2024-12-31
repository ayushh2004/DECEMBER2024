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
