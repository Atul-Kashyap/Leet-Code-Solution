Approach 1: Brute Force
Time Complexity: O(N^2)
Space Complexity: O(1)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                profit = max(profit, prices[j] - prices[i]);
            }
        }
        return profit;
    }
};

Approach 2: DP
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int profit = 0;
        for(int cost : prices){
            if(minprice > cost)
                minprice = cost;
            else if(cost - minprice > profit)
                profit = cost - minprice;
                
        }
        return profit;
    }
};
