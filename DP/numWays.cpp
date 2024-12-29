class Solution {
public:
    int n;
    int k;
    int t[1001][1001];
    const int MOD=1e9+7;

    int solve(int i,int j,vector<vector<long long>> &freq,string &target){
        if(i==n){
            return 1;
        }
        if(j==k){
            return 0;
        }
        if(t[i][j]!=-1) return t[i][j];
        int not_take=solve(i,j+1,freq,target)%MOD;
        int take=(freq[target[i]-'a'][j]*solve(i+1,j+1,freq,target))%MOD;
        return t[i][j]=(take+not_take)%MOD;
    }

    int numWays(vector<string>& words, string target) {
        if (words.empty() || target.empty()) return 0;
        n=target.length();
        k=words[0].size();
        vector<vector<long long>> freq(26,vector<long long>(k));
        for(int index=0;index<k;index++){
            for(string &word:words){
                freq[word[index] - 'a'][index]++;
            }
        }
        memset(t,-1,sizeof(t));
        return solve(0,0,freq,target);
    }
};
