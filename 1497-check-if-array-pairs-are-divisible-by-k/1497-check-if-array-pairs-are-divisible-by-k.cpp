class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>memo(k); 
        for(int currVal : arr){
            int currRem = ((currVal % k) + k) % k;
            memo[currRem]++; 
        }
        for(int i =0;i<=k/2;i++){
            if( i == 0){
                if(memo[i] % 2 != 0) return false;
            }else{
                int y = k - i;
                if(memo[i] != memo[y]) return false;
            }
        }
        return true;
    }
};