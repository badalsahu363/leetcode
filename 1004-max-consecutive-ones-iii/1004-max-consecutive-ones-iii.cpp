class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int head,tail=0,ans = 0;
        for(head =0;head<nums.size();head++){
            if(nums[head] == 0) k--;
            while(k < 0){
                if(nums[tail] == 0) k++;
                tail++;
            }
            ans = max(ans,head-tail+1);
        }
        return max(ans,head-tail);
    }
};