//Approach 1: 
// Time Complexity : o(N)

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l++]) != tolower(s[r--])) {
                return false;
            }
        }
        return true;
    }
};

//Approach 2: 
// Time Complexity : o(N)

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0; i < s.size(); ++i){
            if((s[i] >= 'A' && s[i] <= 'Z') || ( s[i] >= 'a' &&  s[i] <= 'z' ) || (s[i] >= '0' && s[i] <= '9'))
                str += tolower((char)s[i]);
            else
                continue;
        }
        if(equal(str.begin(), str.end(), str.rbegin()))
            return true;
     return false;     
    }
};



