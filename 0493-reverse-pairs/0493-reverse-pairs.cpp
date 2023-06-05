class Solution {
public:
    
    int merge(vector<int>& nums, int l, int mid, int h) {
        
        int total = 0;
        int j = mid+1 ;
        for(int i = l; i<=mid; i++) {
            while(j<=h && nums[i] > 2ll*nums[j]) {
                j++;
            }
            total += (j-(mid+1));
        }
        vector<int> temp;
        int left = l, right = mid+1;
        while(left<=mid && right<=h) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid) {
            temp.push_back(nums[left++]);
        }
        while(right<=h) {
            temp.push_back(nums[right++]);
        }
        for(int i=l; i<=h; i++) {
            nums[i] = temp[i-l];
        }
        return total;
    }
    
    int mergeSort(vector<int>& nums, int l, int h) {
        
        if(l >= h) return 0;
        int mid = (l+h)/2;
        int p = mergeSort(nums, l, mid);
        p += mergeSort(nums, mid+1, h);
        p += merge(nums, l, mid, h);
        return p;
        
    } 
    
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
        
    }
};