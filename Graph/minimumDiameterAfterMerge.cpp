class Solution {
    
    private:
    unordered_map<int,vector<int>> buildAdj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    pair<int,int> bfs(unordered_map<int,vector<int>> &adj,int source){
        queue<int> q;
        q.push(source);
        unordered_map<int,bool> visited;
        visited[source]=true;
        int distance=0;
        int farthestNode=source;
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                int curr=q.front();
                q.pop();
                farthestNode=curr;
                for(auto &ngbr:adj[curr]){
                    if(visited[ngbr]==false){
                        visited[ngbr]=true;
                        q.push(ngbr);
                    }
                }
            }
            if(!q.empty()) distance++;
        }
        return {farthestNode,distance};
    }
    int findDiameter(unordered_map<int,vector<int>> adj){
        //step1 find farthest node from random node 0
        auto [farthestNode, dist]=bfs(adj, 0);
        //step 2 the farthestNode we got is the the onr end of adj
        //step3 find the farthest from the above node -> that will be the other end
        auto [otherEndNode, diameter]=bfs(adj, farthestNode);
        return diameter;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1=buildAdj(edges1);
        unordered_map<int,vector<int>> adj2=buildAdj(edges2);
        int d1=findDiameter(adj1);
        int d2=findDiameter(adj2);
        int combined=(d1+1)/2 + (d2+1)/2 + 1;
        return max({d1,d2,combined});
    }
};
