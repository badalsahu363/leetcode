class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int head,tail=0,sum =0,ans = INT_MAX;
        for(head =0;head<nums.size();head++){
            sum += nums[head];
            while(sum >= target){
                ans = min(ans,head-tail+1);
                sum -= nums[tail];
                tail++;
            }
        }
        return ans == INT_MAX?0:ans;
    }
};