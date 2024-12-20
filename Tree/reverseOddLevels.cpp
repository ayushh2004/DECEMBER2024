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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> levelNodes;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                levelNodes.push_back(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(level%2==1){
                int i=0,j=levelNodes.size()-1;
                while(i<j){
                    int tempVal=levelNodes[i]->val;
                    levelNodes[i]->val=levelNodes[j]->val;
                    levelNodes[j]->val=tempVal;
                    i++;j--;
                }
            }
            level++;
        }
        return root;
    }
};
