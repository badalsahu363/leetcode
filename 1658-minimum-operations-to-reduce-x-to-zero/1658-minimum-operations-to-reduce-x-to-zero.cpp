class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int sum = accumulate(nums.begin(),nums.end(),0);
         int reqSum = sum-x;
        if(reqSum == 0) return nums.size();
           if(reqSum <0) return -1;
        int tail=0,head=0,mxlen=0,mysum=0;
        
        
        
        for(head =0; head < nums.size();head++){
            mysum += nums[head];
            while(mysum > reqSum){
                mysum -= nums[tail];
                tail++;
            }
            if(mysum == reqSum) {
                mxlen = max(mxlen, head-tail+1);
            }
        }
        return (mxlen==0)?-1:(nums.size()-mxlen);
    }
};