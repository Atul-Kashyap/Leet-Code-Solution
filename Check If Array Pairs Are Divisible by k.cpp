class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int sz = arr.size();
        vector<int> f(k, 0);
        for(int i = 0; i < sz; i++){
            arr[i] = ( (arr[i] % k) + k) % k;
            f[arr[i]]++;
        }
        for(int i = 0; i < k; ++i){
            if( i == 0){
                if(f[i] % 2 == 0)
                    continue;
                else
                    return false;
            }
            else{
                if(i == k/2 && f[i] % 2 == 0)
                    continue;
                
                else if(f[i] == f[k-i])
                    continue;
                
                else 
                    return false;
            }
        }
           
        return true;
    }
};



