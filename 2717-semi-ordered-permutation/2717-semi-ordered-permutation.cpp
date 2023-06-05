class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int ans = 0;
        int id1 = -1,idn = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                id1 = i;
                break;
            }
        }
        
        if(id1 != 0){
            for(int i = id1;i>=1;i--){
                swap(nums[i],nums[i-1]);
                ans++;
            }
        }
        
         for(int i=0;i<n;i++){
            if(nums[i] == n){
                idn = i;
                break;
            }
        }
        
        if(idn != n-1){
            for(int i = idn;i<n-1;i++){
                swap(nums[i],nums[i+1]);
                ans++;
            }
        }
        return ans;
    }
};