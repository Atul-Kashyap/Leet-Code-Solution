Approach 1: Brute Force
Time Complexity : O(n^2)
Auxiliary space : O(1)

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int area = 0;
//         for(int i = 0; i < n; ++i){
//             for(int j = i+1; j < n; ++j){
//                 area = max(area, min(height[i],height[j]) * (j-i));
//             }
//         }
//         return area;
//     }
// };


Approach 2: Two pointer
Time Complexity : O(n)
Auxiliary space : O(1)


// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int area = 0;
//         int l = 0, r = n-1;
//         while(l < r){
//             if(height[l] > height[r]){
//                 area = max(area, height[r] * (r-l));
//                 r--;
//             }
//             else{
//                 area = max(area, height[l] * (r-l));
//                 l++;
//             }
//         }
//       return area;  
//     }
// };


