class Solution {
    private:
    int solve(int idx,int d,vector<int>& jobDifficulty){
        int n=jobDifficulty.size();
        if(d==1){
            int maxElement=*max_element(jobDifficulty.begin()+idx,jobDifficulty.end());
            return maxElement;
        }
        if(t[idx][d]!=-1) return t[idx][d];
        int maxD=jobDifficulty[idx];
        int finalResult=INT_MAX;

        for(int i=idx;i<=n-d;i++){
            maxD=max(maxD,jobDifficulty[i]);
            int result=maxD+solve(i+1,d-1,jobDifficulty);
            finalResult=min(finalResult,result);
        }
        return t[idx][d]=finalResult;
    }
public:
    int t[301][1001];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        memset(t,-1,sizeof(t));
        if(n<d) return -1;
        return solve(0,d,jobDifficulty);
    }
};
