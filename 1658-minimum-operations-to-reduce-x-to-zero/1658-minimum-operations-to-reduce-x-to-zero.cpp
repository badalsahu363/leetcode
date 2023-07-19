class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int reqSum = sum - x;
        if (reqSum < 0) {
            return -1;
        }
        if (reqSum == 0) {
            return nums.size();
        }
        
        int tail = 0, mxlen = -1, mysum = 0;
        for (int head = 0; head < nums.size(); ++head) {
            mysum += nums[head];
            while (mysum > reqSum && tail <= head) {
                mysum -= nums[tail];
                tail++;
            }
            if (mysum == reqSum) {
                mxlen = max(mxlen, head - tail + 1);
            }
        }
        
        return (mxlen == -1) ? -1 : (nums.size() - mxlen);
    }
};
