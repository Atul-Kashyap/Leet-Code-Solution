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

// Approach 1: Using HashSet[Accepted]
// Time Complexity : O(N)
// Space Complexity : O(N)
    
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        map<int, bool> mp;
        return Helper(root, k, mp);
    }
    bool Helper(TreeNode* root, int k, map<int, bool> &mp){
        if(root == NULL)
            return false;
        if(mp.count(k - root -> val))
            return true;
            mp[root->val] = 1;
        return (Helper(root->left, k, mp) || Helper(root->right, k, mp));
    }
};



// Approach 2: Using BFS
// Time Complexity : O(N)
// Space Complexity : O(N)
    
    
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
          return false;
        queue<TreeNode*> q;
        map<int, bool> mp;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != NULL){
                if(mp[k - temp -> val])
                    return true;
                mp[temp->val] = true;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
       return false; 
    }
};




// Approach 3: Inorder Traversal
// Time Complexity : O(N)
// Space Complexity : O(N)



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
          return false;
        vector<int> arr;
        inorder(root, arr);
        int l = 0, r = arr.size() - 1;
        while(l < r){
            int sum = arr[l] + arr[r];
            if(sum == k)
                return true;
            else if(sum < k)
                ++l;
            else
                --r;
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int> &arr){
        stack<TreeNode*> st;
        while(root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            arr.push_back(root->val);
            root = root -> right;
        }
    } 
    
};




