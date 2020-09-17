// Approach 1: Brute Force
// Time Complexity: O(2^n)
// Space Complexity: O(n)


class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        return Climb(0, n);
    }
    int Climb(int i, int n){
        if(i > n)
            return 0;
        if(i == n)
            return 1;
        return Climb(i+1, n) + Climb(i+2, n);
    }
};



// Approach 2: Recursion with Memoization
// Time Complexity:O(n)
// Space Complexity:O(n)

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        vector<int> dp(n+1, -1);
        dp[n] = 1;
        return Climb(dp, 0, n);
    }
    int Climb(vector<int> &dp, int i, int n){
        if(i > n)
            return 0;
        if(i == n)
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = Climb(dp, i+1, n) + Climb(dp, i+2, n);
        return dp[i];
    }
};


// Approach 3: Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n)



class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        if(n == 1)
            return 1;
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Approach 4: Fibonacci Number
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
       // fib(i) = fib(i-1) + fib(i-2)
        int first = 1, second = 2;
        for(int i = 3; i <= n; ++i){
            int temp = first + second;
            first = second;
            second = temp;
        }
       return second;
    }
};
    

// Approach 5: Fibonacci Formula
// Time Complexity: O(logn)
// Space Complexity: O(1)


class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        double ans = pow(((1+sqrt(5))/2),n+1) - pow(((1-sqrt(5))/2),n+1);
        return (int)(ans/sqrt(5));
    }
};
   





    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
