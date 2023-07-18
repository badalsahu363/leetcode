class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head,tail =0,ans = 0;
        unordered_map<int,int>mpp;
        for(head = 0;head<s.size();head++){
            mpp[s[head]]++;
            while(mpp[s[head]] > 1){
                ans = max(ans,head-tail);
                mpp[s[tail]]--;
                tail++;
            }
        }
        return max(ans,head-tail);
    }
};