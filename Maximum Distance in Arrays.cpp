// Approach 1: Brute Force [TLE]
// Time Complexity : O((N * X)^2), X refers to the average number of elements in each array.
// Space Complexity : O(1)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int r = arrays.size();
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < arrays[i].size(); ++j){
                for(int k = i+1; k < r; ++k){
                    for(int l = 0; l < arrays[k].size(); ++l){
                        res = max(res, abs(arrays[i][j] - arrays[k][l]));
                    }
                }
            }
        }
        return res;
    }
};

// Approach 2: Better Brute Force [TLE]
// Time Complexity : O(N ^2)
// Space Complexity : O(1)
    
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int r = arrays.size();
        int ans = 0;
        for(int i = 0; i < r; ++i){
            for(int j =i+1; j < r; ++j){
                ans = max(ans, abs(arrays[j][arrays[j].size() - 1] - arrays[i][0]));
                ans = max(ans, abs(arrays[i][arrays[i].size() - 1] - arrays[j][0]));
            }
        }
        return ans;
    }
};


// Approach 3: MIn Max
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, min_val = arrays[0][0], max_val = arrays[0][arrays[0].size() - 1];
        int sz = arrays.size();
        for(int i = 1; i < sz; ++i){
            res = max(res, max(abs(arrays[i][arrays[i].size() - 1] - min_val), abs(max_val - arrays[i][0])));
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i][arrays[i].size() - 1]);
            
        }
       return res; 
    }
};
