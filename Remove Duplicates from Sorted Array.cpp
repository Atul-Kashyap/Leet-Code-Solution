Approach 1: Two pointer
Time Complexity : O(N);
Space Complexity : O(1);

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) 
           return 0;
        int i = 0, j = 1;
        while(j < nums.size()){
            if(nums[i] != nums[j])
                nums[++i] = nums[j];
            j++;   
        }   
       
      return i+1;  
        
    }
};


Approach 2: counting the repetitive elelment
Time Complexity : O(N);
Space Complexity : O(1);

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) 
           return 0;
        int cnt = 0;
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i-1]) cnt++;
            else
                nums[i-cnt] = nums[i];
        } 
       return n - cnt; 
    }
};
