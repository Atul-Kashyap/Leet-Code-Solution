// Approach 1:
// Time Complexity : O(NLog(N))

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n; i ; i /= 2){
            if(i & 1)
                res *= x;
            x *= x;
        }
       return n >= 0 ? res : 1/res; 
    }
};

// Approach 2:
// Time Complexity : O(NLog(N))

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        bool flag = 1;
        if(n < 0){
           flag = 0;
           n = abs(n);
        }    
        while(n > 0){
            if(n & 1)
            res = res * x;
          
        x *= x;
        n >>= 1;
                
        }
     return flag == 1 ? res : 1/res;
    }
};
