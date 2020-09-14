// Approach 1: Brute Force
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        for(int i = 0; i < len; ++i){
           if(str[i] >= 'A' && str[i] <= 'Z'){
              char ch = str[i];
               ch = char((int) ch | 32);
               str[i] = ch;
           }
        }
    return str;
    }
};

// Approach 2: Brute Force
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        for(int i = 0; i < len; ++i){
           if(str[i] >= 'A' && str[i] <= 'Z'){
              char ch = str[i];
               ch = char((int) ch + 32);
               str[i] = ch;
           }
        }
    return str;
    }
};


// Approach 3: Using transform(str.begin(), str.end(), ::tolower)
// Time Complexity : O(N)
// Space Complexity : O(1)
    
 class Solution {
public:
    string toLowerCase(string str) {
        
        transform(str.begin(), str.end(), ::tolower);
        
    return str;
    }
};
   
    
    
    
// Approach 4: Hash Map
// Time Complexity : O(N)
// Space Complexity : O(N)   
    
    
    


