Approach 1: Brute Force
Time Compleity: O(N), where N is the length of string
Space Comlexity: O(1)

class Solution {
public:
    int balancedStringSplit(string s) {
        int len = s.size();
        int cnt = 0, ans = 0;
        for(int i = 0; i < len; ++i){
            if(s[i] == 'L')
                cnt++;
            else
                cnt--;
        if(cnt == 0)
            ans++; 
        }
       return ans; 
    }
};


Approach 2: Brute Force
Time Compleity: O(N), where N is the length of string
Space Comlexity: O(1)

class Solution {
public:
    int balancedStringSplit(string s) {
        int len = s.size();
        int l = 0, r = 0, ans = 0;
        for(int i = 0; i < len; ++i){
            if(s[i] == 'L'){
                l++;
                if(l == r)
                    ans++;
            }
            else{
               r++;
                if(l == r)
                    ans++; 
            }
        }
        
       return ans; 
    }
};
