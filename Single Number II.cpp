Approach 1: HashSet { 3×(a+b+c)−(a+a+a+b+b+b+c)=2c }
Time Complexity: O(N)
Auxiliary Space: O(N)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> HashSet;
        long long array_sum = 0, set_sum = 0;
        for(int elem : nums){
            HashSet.insert(elem);
            array_sum += elem; 
        }
        for(int elem : HashSet){
            set_sum += elem;
        }
        return (int)(3 * set_sum - array_sum)/2;        
    }
};


Approach 2: HashMap
Time Complexity: O(N)
Auxiliary Space: O(N)


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int,int> Hashmap;
        for(int elem : nums)
            Hashmap[elem] += 1;
        for(auto it : Hashmap){
            if(it.second == 1)
                return it.first;
        }
        return 0;
    }
};


Approach 3: Bitwise Operators : NOT, AND and XOR
Time Complexity: O(N)
Auxiliary Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;
        for(int elem : nums){
            seenOnce = ~seenTwice & (seenOnce ^ elem);
            seenTwice = ~seenOnce & (seenTwice ^ elem);
        }
        return seenOnce;
    }
};

Note:-
There are 3 key parts:

Split each original number into a group of numbers, which are the power of 2. E.g., 5 = 1+4; 7=1+2+4; 8=8

Each number after splitting is the power of 2, such as 1,2,4,8,16 .... Use two hash maps to save them.

If this is the first time we see a number, save it in hash-map-once.
If a number has already been saved in hash-map-once, it means this is the second time we see it. Remove it from hash-map-once and save it in hash-map-twice.
If a number has already been in hash-map-twice, it means this is the third time we see it.
Remove it from hash-map-twice and we are done with it. This number has been removed from both hash maps.
After processing all numbers, hash-map-once only contains the group of power-of-two numbers splitted from the single orgininal number. 
hash-map-twice is 0. We could simply collect all numbers in hash-map-once and add them together to get the single original number.
[Optimization] Because all numbers after splitting are the power of 2, such as 1,2,4,8,16, etc., we assume there are at most 32 types of numbers after splitting. 
We could save memory by squashing the two hash maps into two 32-bit integers. Each power-of-2 number could be represented by 1 bit in the 32-bit integer.

hash-map-once -> seenOnce
hash-map-twice -> seenTwice

After processing all numbers, the value of integer seenOnce is exactly the sum of all numbers left in hash-map-once.
It is not necessary to replace the two hash-maps with two 32-bit integers. If we simply use 1 hash-map to save the occurrences of all power-of-2 numbers, 
the size of the hash-map is at max 32. We can still consider it as a constant memory space solution and the space complexity is still O(0). With the hash map, 
we could easily extend the problem to n duplicated numbers. E.g., All numbers are duplicated 100 times except 1. Find out this single number.
