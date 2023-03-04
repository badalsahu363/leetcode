class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>memo(k);
        for(auto it : arr){
            int currrem = ((it % k)+k) % k;
            memo[currrem]++;
        }
        
        for(int i=0;i<=k/2;i++){
            if(i == 0){
                if(memo[i] % 2 != 0) return false;
            }else{
                int y = k - i;
                if(memo[i] != memo[y]) return false;
            }
        }
        return true;
    }
};