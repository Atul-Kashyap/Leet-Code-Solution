Approach 1: Sort
Time Complexity: O(NlogN), where N is the length of A.
Space Complexity: O(N).

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> squareArr;
        for(int elem : A)
           squareArr.push_back(elem * elem);
        sort(squareArr.begin(), squareArr.end());
        return squareArr;
    }
};


Approach 1: Two Pointer
Time Complexity: O(N), where N is the length of A.
Space Complexity: O(N).

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int j = 0;
        int n = A.size();
        vector<int> arr(n);    
        while(j < n && A[j] < 0) 
            j++;
        int i = j-1, t = 0;
        while( i >= 0 && j < n){
            if(A[i]*A[i] < A[j]*A[j]){
                arr[t++] = A[i]*A[i];
                i--;
            }
            else{
                arr[t++] = A[j]*A[j];
                j++;
            }
        }
        while(i >= 0){
             arr[t++] = A[i]*A[i];
                i--;
            
        }
        while(j < n){
             arr[t++] = A[j]*A[j];
                j++;
        }       
        return arr;
    }
};
