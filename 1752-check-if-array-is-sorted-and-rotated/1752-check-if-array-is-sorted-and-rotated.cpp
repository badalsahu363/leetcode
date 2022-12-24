class Solution {
public:
    bool check(vector<int>& nums) {
         int n = nums.size();
  int breakPoint = 0;
  for (int i = 1; i < n; i++) 
  {
    if (nums[i - 1] > nums[i]) 
    {
      breakPoint++;
    }
  }
  if (nums[n - 1] > nums[0])
    breakPoint++;

  if (breakPoint <= 1)
    return true;
  return false;
    }
};