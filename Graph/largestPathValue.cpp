class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length();
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<vector<int>> t(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                t[i][colors[i]-'a']=1;
            }
        }
        int answer=0;
        int countNodes=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            countNodes++;
            answer=max(answer,t[u][colors[u]-'a']);
            for(int &v:adj[u]){
                for(int i=0;i<26;i++){
                    t[v][i]=max(t[v][i],t[u][i]+(colors[v]-'a'==i));
                }
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        if(countNodes!=n) return -1;
        return answer;
    }
};
