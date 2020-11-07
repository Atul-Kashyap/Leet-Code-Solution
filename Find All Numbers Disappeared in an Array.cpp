// Approach 1: Using Hash Map
// Time Complexity : O(N)
// Auxiliary Space : O(N)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> hash;
        for(int i = 0; i < n; i++){
            hash[nums[i]] = true;
        }
        vector<int> ans;
        for(int i = 1; i <= n; ++i){
            if(!hash[i])
            ans.push_back(i);
        }
        
      return ans;  
    }
};


// Approach 2: O(1) Space InPlace Modification Solution
// Time Complexity : O(N)
// Auxiliary Space : O(1)


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return {};
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int a = abs(nums[i]);
            if(a == n)
                nums[0] = - abs(nums[0]);
            else {
                nums[a] = - abs(nums[a]);
            }
        }
        for(int i = 1; i < n; ++i){
            if(nums[i] >  0)
                ans.push_back(i);
        }
        if(nums[0] > 0)
            ans.push_back(n);
        return ans;
    }
};
