class Solution {
public:
    void Permutations(int ind, vector<int> &nums, set<vector<int>> &ans){
        if(ind==nums.size())
            ans.insert(nums);

        for(int i=ind;i<nums.size();i++){      
            if(i>ind && nums[i]==nums[ind]) continue;
            swap(nums[i],nums[ind]);
            Permutations(ind+1, nums, ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>> vec;
        Permutations(0, nums, ans);
        for(auto it:ans){
            vec.emplace_back(it);
        }
        return vec;
    }
};