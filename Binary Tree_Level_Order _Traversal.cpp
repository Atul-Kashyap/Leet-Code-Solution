Approach : BFS
Time Complexity : O(N)
Auxiliary Space : O(N)
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        vector<vector<int>> ans;
        vector<int> arr;
        queue<TreeNode*> qt;
        qt.push(root); 
        
        while(!qt.empty()){
            int n = qt.size();
            for(int i = 0; i < n; i++){
                TreeNode* curr = qt.front();
                qt.pop();
                arr.push_back(curr->val);
                if(curr->left) 
                    qt.push(curr->left);
                if(curr->right)
                    qt.push(curr->right);    
            }
            ans.push_back(arr);
            arr.clear();
        }
        return ans;   
    }
};

