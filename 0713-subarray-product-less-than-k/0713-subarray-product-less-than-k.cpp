class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int head,tail=0,ans=0,pro=1;
        for(head =0;head<nums.size();head++){
            pro *= nums[head];
            while(pro >= k){
                pro = pro/nums[tail];
                tail++;   
            }
            ans += (head-tail+1);
        }
        return ans;
    }
};