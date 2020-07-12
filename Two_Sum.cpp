// Approach 1: Brute force 
// Time complexity : O(N^2)
// Space complexity : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for(int i = 0; i < nums.size(); ++i){
           for(int j = i+1; j < nums.size(); j++){
               if(nums[i] + nums[j] == target)
                   return {i , j};
               else
                   continue;
           }
       }
        return { };
    }    
};


// Approach 2: Sorting, Two pointer
// Time complexity : O(NLog(N))
// Space complexity : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v = nums;
        sort(nums.begin(),nums.end());
        int l = 0, r = nums.size() - 1;
        while(nums[l] + nums[r] != target) {
            if(nums[l] + nums[r] < target)
                l++;
            else if(nums[l] + nums[r] > target)
                r--;
            
        }
     l = find(v.begin(), v.end(), nums[l]) - v.begin();
     r = abs(find(v.rbegin(), v.rend(), nums[r]) - v.rend()+1);
        return {l,r};
    }    
};



// Approach 3: Hash Table 
// Time complexity : O(N)
// Space complexity : O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> table;
      for(int i = 0; i < nums.size(); i++){
          if(table.find(target - nums[i]) != table.end())
              return {i,table[target - nums[i]]};
          else
             table[nums[i]] = i;
      }
        return { };
    }    
};
