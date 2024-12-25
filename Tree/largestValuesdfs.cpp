/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> result;
    private:
    void dfs(TreeNode* root,int depth){
        if(root==nullptr) return ;
        if(depth==result.size()){
            result.push_back(root->val);
        }else{
            result[depth]=max(result[depth],root->val);
        }
        if(root->left) dfs(root->left,depth+1);
        if(root->right) dfs(root->right,depth+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        dfs(root,0);
        return result;
    }
};
