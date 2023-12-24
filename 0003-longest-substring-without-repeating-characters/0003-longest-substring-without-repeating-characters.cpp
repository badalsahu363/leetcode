class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head,tail=0,ans = 0;
        unordered_map<char,int>mpp;
        for(head =0;head<s.size();head++){
            mpp[s[head]]++;
            while( mpp[s[head]]>1){//failing condition
              ans = max(ans,head-tail);
              mpp[s[tail]]--;
              tail++;  
            }
        }
        return max(ans,head-tail);
    }
};