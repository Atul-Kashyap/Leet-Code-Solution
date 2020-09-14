// Approach 1: Brute Force
// Time Complexity : O(N), where N is the length of word and O(26 * N).
// Space Complexity : O(1)

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int  word_len = word.size();
        int i = 0, j = 0, ans = 0;
        while( i < word_len){
            int l = j, r = j+1;
            while(l >= 0){
                if(word[i] == keyboard[l])
                    break;
                l--;
            }
            while(r < 26){
                if(word[i] == keyboard[r])
                    break;
                r++;
            }
            if(l < 0 && r < 26){
               ans +=  r-j;
               j = r;
            }
            else{
                ans += j-l;
                j = l;
            }
              
            i++;
        }
       return ans; 
    }
};

// Approach 2: Hash Map
// Time Complexity : O(N), where N is the length of word
// Space Complexity : O(N)

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int prev = 0, ans = 0;
        unordered_map<char, int> hash;
        for(int i = 0; i < 26; ++i){
            hash[keyboard[i]] = i;
        }
        for(char elem : word){
           ans += abs(prev - hash[elem]);
           prev = hash[elem];
        }  
     return ans;   
    }
};
