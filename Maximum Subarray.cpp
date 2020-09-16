//Approach 1: Recursion
//Time Complexity: O(NLogN)
//Space Complexity: O(LogN)


class Solution {
public:
    int crossmaxsum(vector<int> &nums, int left, int right, int p){
        if(left == right)
            return nums[left];
        int left_maxsum = INT_MIN;
        int curr_sum = 0;
        for(int i = p; i > left - 1; i--){
            curr_sum += nums[i];
            left_maxsum = max(curr_sum, left_maxsum);
        }
        
        
        int right_maxsum = INT_MIN;
        curr_sum = 0;
        for(int i = p+1; i < right+1; i++){
            curr_sum += nums[i];
            right_maxsum = max(curr_sum, right_maxsum);
        }
       return left_maxsum + right_maxsum; 
    }
    
    int helper(vector<int> &nums, int left, int right){
        if(left == right)
            return nums[left];
        int p = (left + right)/2;
        int left_sum = helper(nums, left, p);
        int right_sum = helper(nums, p+1, right);
        int cross_sum = crossmaxsum(nums, left, right, p);
        return max(max(left_sum, right_sum), cross_sum);
    }
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        return helper(nums, 0, sz - 1);
    }  
};






//Approach 2: Greedy 
//Time Complexity: O(N)
//Space Complexity: O(1)


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        int max_sum = nums[0], global_maxsum = nums[0];
        for(int i = 1; i < sz; ++i){
            max_sum = max(max_sum+nums[i], nums[i]);
            global_maxsum = max_sum > global_maxsum ? max_sum : global_maxsum;
        }
        return global_maxsum;
    }
};



//Approach 3: Dynamic Programming (Kadanes Algorithm)
//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        int max_sum = nums[0];
        for(int i = 1; i < sz; ++i){
            if(nums[i-1] > 0)
                nums[i] += nums[i-1];
            max_sum = max(nums[i], max_sum);
        }
        return max_sum;
    }
};







