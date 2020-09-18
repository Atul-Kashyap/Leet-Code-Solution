//Approach 1: Mathematical: Sum of First k Natural Numbers, sqrt(N) time
// Time Complexity: sqrt(N)
// Space Complexity: O(1)



class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 0;
        int upper_limit = (int) (sqrt(2*N + 0.25) - 0.5);
        for(int k = 1; k <= upper_limit; ++k){
            if((N - k * ( k + 1 ) / 2) % k == 0)
                count++;
        }
        return count;
    }
};

//Approach 2: Mathematical: Mathematical: Decrease N Gradually, sqrt(N) time
// Time Complexity: sqrt(N)
// Space Complexity: O(1)


class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 0;
        int upper_limit = (int) (sqrt(2*N + 0.25) - 0.5);
        for(int k = 1; k <= upper_limit; ++k){
            N -= k;
            if(N % k == 0)
                count++;
        }
        return count;
    }
};
