// Approach 1: Priority Queue
// Time Complexity :(NLogN)
// Space Complexity : O(N)


class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[0] < b[0];
        
    }
   int minMeetingRooms(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        if(sz == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), comp);
        pq.push(intervals[0][1]);
        for(int i = 1; i < sz; ++i){
            if(intervals[i][0] >= pq.top())
                pq.pop();
        pq.push(intervals[i][1]);

        }
       return pq.size(); 
    }
};

// Approach 2: Chronological Ordering
// Time Complexity :(NLogN)
// Space Complexity : O(N)



class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        if(sz == 0)
            return 0;
        vector<int> start(sz);
        vector<int> end(sz);
        for(int i = 0; i < sz; ++i){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int s_ptr = 0, e_ptr = 0;
        int usedrooms = 0;
        while(s_ptr < sz){
            if(start[s_ptr] >= end[e_ptr]){
                usedrooms -= 1;
                e_ptr += 1;
            }
            
            usedrooms += 1;
            s_ptr += 1;
        }
        
        return usedrooms;
    }
};
