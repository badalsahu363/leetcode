class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {
            int start = 0;
            int end = nums.size() - 1;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                 //comparision
                if (nums[mid] == target)
                {
                    return mid;
                }
                
                //decision 
                if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
                 
                // //decision for array in descending order
                // if (nums[mid] > target)
                // {
                //     start = mid + 1;
                // }
                // else
                // {
                //    end = mid - 1;
                // }
                
            }
            return -1;
        }
};