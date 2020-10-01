// Approach 1: Greedy
// Time Complexity: O(N)
// Space Complexity: O(1) 

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.size();
        vector<int> last_pos(26);
        for(int i = 0; i < len; ++i){
            last_pos[S[i] - 'a'] = i;
        }
        vector<int> ans;
        int j = 0, pos = 0;
        for(int i = 0; i < len; ++i){
            j = max(j, last_pos[S[i] - 'a']);
            if(i == j){
                ans.push_back(i - pos + 1);
                pos = i+1;
            }
        }
       return ans; 
    }
};
