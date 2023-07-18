class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int head,tail=0,sum =0,ans = 0;
        unordered_map<int,int>mpp; // element and frequency
        for(head =0;head<nums.size();head++){
            mpp[nums[head]]++;
            while(mpp[nums[head]] > 1){
                ans = max(ans,sum);
                sum -= nums[tail];
                mpp[nums[tail]]--;
                tail++;
            }
            //operation performed
            if(mpp[nums[head]] == 1){
                sum += nums[head];
            }
        }
        return max(ans,sum);
    }
};