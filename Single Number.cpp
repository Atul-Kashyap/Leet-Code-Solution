Approach 1: Brute Force
Time Complexity : O(N^2)
Auxiliary Space : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int val_1 : nums){
            int freq = 0;
            for(int val_2 : nums){
                if(val_1 == val_2)
                    freq++;
            }
            if(freq == 1)
                return val_1;
        }
        return 0;
    }
};


Approach 2: Hash Table
Time Complexity : O(N)
Auxiliary Space : O(N)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto val : nums)
            hash[val] += 1;
        for(int i = 0; i < nums.size(); ++i){
            if(hash[nums[i]] == 1)
                return nums[i];
        }
        return 0;
    }
};



Approach 3: Math { 2∗(a+b+c)−(a+a+b+b+c)=c }
Time Complexity : O(N)
Auxiliary Space : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> HashSet;
        int Sum_Of_Nums = 0, Sum_Of_HashSet = 0;
        for(int val : nums){
            if(HashSet.find(val) == HashSet.end()){
                HashSet.insert(val);
                Sum_Of_HashSet += val;
            }
            
            Sum_Of_Nums += val;   
        }
     return 2 * Sum_Of_HashSet - Sum_Of_Nums;
    }
};


Approach 4: Bit Manipulation { a ^ a = 0, a ^ 0 = a, a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b }
Time Complexity : O(N)
Auxiliary Space : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int val : nums)
            ans ^= val;
        return ans;
    }
};
