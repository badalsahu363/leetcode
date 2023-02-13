class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans  = 0;
        for(int i=31;i>=0;i--){
            int cnt = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j] & (1<<i)){ //checks array ro ith bit is set or not
                    cnt++;
                }
            }
            if(cnt % 3  != 0) ans  += (1<<i);  // 2 to the power of i we will add to the 
            //ans and proceeed further 
        }
        return ans;
    }
};