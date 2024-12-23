#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> topoSort(int V,vector<int> adj[]){
        vector<int> indegree(V);
        for(int i=0;i<V;i++){
            for(int it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto ngbr:adj[node]){
                indegree[ngbr]--;
                if(indegree[ngbr]==0) q.push(ngbr);
            }
        }
        return topo;
    }
};

int main() {
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}
