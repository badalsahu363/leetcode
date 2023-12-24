class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int head,tail =0,ans =0;
        for(head = 0;head < nums.size();head++){
            if(nums[head] == 0) k--;
            while(k < 0){ //failing condition 
                 if(nums[tail] == 0) k++;
                 tail++; // moves ahead from first
            }
            ans = max(ans,head-tail+1);
        }
        return ans = max(ans,head-tail);
    }
};