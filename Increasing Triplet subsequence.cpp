// Approach 1: Brute Force
// Time Complexity : O(N^2)
// Auxiliary space : O(1)


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-2; ++i){
            for(int j = i+1; j < n-1; ++j){
                if(nums[i] < nums[j]){
                    for(int k = j+1; k < n; ++k){
                    if(nums[i] < nums[j] && nums[j] < nums[k])
                        return true;
                   }
                }
                
            }
        }
        return false;
    }
};



// Approach 1: Linear Search
// Time Complexity : O(N)
// Auxiliary space : O(1)

    
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_num = INT_MAX, second_num = INT_MAX;
        for(int elem : nums){
            if(elem <= first_num)
                first_num = elem;
            else if(elem <= second_num)
                second_num = elem;
            else
                return true;
        }
        return false;
    }
};
