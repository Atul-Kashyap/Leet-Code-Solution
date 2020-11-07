Approach 1 : Hash map
Time Complexity : O(N)
Space complexity : O(N)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(mp[nums[i]] == 0)
                mp[nums[i]] = 1;
            else
                ans.push_back(nums[i]);
        }
      return ans; 
    }
};

Approach 2 : mutation of array
Time Complexity : O(N)
Space complexity : O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
       for(int i = 0; i < nums.size(); ++i){
           if(nums[abs(nums[i]) - 1] < 0)
               ans.push_back(abs(nums[i]));
           else
              nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
       }
      return ans; 
    }
};
