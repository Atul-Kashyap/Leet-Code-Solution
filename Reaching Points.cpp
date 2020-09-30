// Approach 1:  Exhaustive Search [Time Limit Exceeded]
// Time Compexity : O(2^(tx+ty)
// Space Complexity : O(tx * ty)

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx == tx && sy == ty)
            return true;
        if(sx > tx || sy > ty)
            return false;
     return reachingPoints(sx, sx+sy, tx, ty) || reachingPoints(sx+sy, sy, tx, ty);   
    }
};

// Approach 2: Work Backwards (Naive Variant) [Time Limit Exceeded]
// Time Compexity : O(max(tx, ty))
// Space Complexity : O(1)

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy){
            if(sx == tx && sy == ty)
                return true;
            if(tx > ty)
                tx -= ty;
            else
                ty -= tx;
        }
        return false;
    }
};


// Approach 3: Work Backwards (Modulo Variant) [Accepted]
// Time Compexity : O(log(max(tx,ty)))
// Space Complexity : O(1)

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy){
            if(tx == sx && ty == sy)
                return true;
            if(tx > ty){
                if(ty > sy)
                    tx %= ty;
                else
                    return (tx - sx) % ty == 0;
            }
            else{
                if(tx > sx)
                    ty %= tx;
                else
                    return (ty - sy) % tx == 0;
            }
        }
        return (tx == sx && ty == sy);
    }
};









