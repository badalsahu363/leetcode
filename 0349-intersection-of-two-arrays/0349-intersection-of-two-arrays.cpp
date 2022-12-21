class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,bool>mpp;
        for(auto i: nums1){
            mpp[i] = true;
        }
        for(auto i:nums2){
            if(mpp.find(i) != mpp.end() and mpp[i] == true){
                ans.push_back(i);
                mpp[i] = false;
            } 
        }
        return ans;
    }
};