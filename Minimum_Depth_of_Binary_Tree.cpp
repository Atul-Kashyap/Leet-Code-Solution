Approach 1: Recursive
Time Complexity : O(N)
Space Complexity : O(H)
H is the height of the Binary tree


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
    int minDepth(TreeNode* root) {
       if (!root) return 0;
    int L = minDepth(root->left);
    int R = minDepth(root->right);
    return 1 + (min(L, R) ? min(L, R) : max(L, R));
    }
};


Approach 2: iterative using BFS
Time Complexity : O(H);
Auxiliary Space : O(H), H = height of tree;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int depth = 1;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(!curr){
                q.push(NULL);
                depth++;
            }
            else{
                if( !curr->left && !curr->right)
                    return depth;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            
        }
        return depth;
       
    }
};
