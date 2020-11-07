// Approach 1: Index as a hash key
// Time Complexity : O(N)
// Auxiliary Space : O(N)


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool one = false;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1)
                one = true;
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        if(!one)
            return 1;
        for(int i = 0; i < n; ++i){
            int a = abs(nums[i]);
            if(a == n)
                nums[0] = -abs(nums[0]);
            else
                nums[a] = - abs(nums[a]);
        }
        for(int i = 1; i < n; ++i){
            if(nums[i] > 0)
                return i;
        }
        if(nums[0] > 0)
            return n;
        
        return n+1;
        
    }
};
