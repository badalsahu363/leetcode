class Solution {
public:
    int minimizedStringLength(string s) {
     int ans =0;
        unordered_map<char,int>mpp;
        for(auto it:s){
            if(mpp[it] == 0){
                mpp[it]++;
                ans++;
            }
        }
        return ans;
    }
};