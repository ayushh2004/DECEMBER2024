class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        if(n<2) return 1;
        vector<vector<int>> gr(n);
        vector<int> indegree(n);
        vector<long long> nodevalue(values.begin(),values.end());
        for(const auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        int c=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            indegree[cur]--;
            long long addvalue=nodevalue[cur]%k==0? 0:nodevalue[cur];
            if(addvalue==0) c++;
            for(int neighbour:gr[cur]){
                if(indegree[neighbour]>0){
                    indegree[neighbour]--;
                    nodevalue[neighbour]+=addvalue;
                    if(indegree[neighbour]==1){
                        q.push(neighbour);
                    }
                }
            }
        }
        return c;
    }
};
