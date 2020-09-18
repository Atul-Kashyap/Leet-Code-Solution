// Approach : Brute Force
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int pop = x % 10;
            x /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX && pop > 7))
                return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
