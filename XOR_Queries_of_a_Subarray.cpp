Approach: DP
Time Complexity: O(N)
Auxiliary Space: O(N)

class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int dp[arr.size()];
        dp[0]=arr[0];
        for(int i=1;i<arr.size();i++)
            dp[i]=arr[i]^dp[i-1];
        vector<int> res;
        for(int i=0;i<q.size();i++)
        {
            if(q[i][0]==0)
            {
                res.push_back(dp[q[i][1]]);
            }
            else
            {
                res.push_back(dp[q[i][1]]^dp[q[i][0]-1]);
            }
        }
        return res;
    }
};
