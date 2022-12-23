class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         int prefix = 0;
        int ans = 0;
        unordered_map<int,int>mp;
        mp[prefix] = -1;
        for(int  i =0;i<nums.size();i++){
           if(nums[i] == 0){
               prefix += -1;
           }else{
                prefix += nums[i];
           }
           
            if(mp.find(prefix) != mp.end()){
                ans = max(ans,i-mp[prefix]);
            }else{
                mp[prefix] = i;
            }
        }
        return ans;
    }
};