class Solution {
     int maxFreq(unordered_map<char,int>&mpp){
        int maxCount = 0;
        for(auto it : mpp){
            maxCount = max(maxCount,it.second);
        }
        return maxCount;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
          int head=0,tail=0,ans =0;
        unordered_map<char,int>mpp;
        for(head = 0;head<answerKey.size();head++){
            mpp[answerKey[head]]++;
            while( head - tail + 1 - maxFreq(mpp) > k){
                mpp[answerKey[tail]]--;
                tail++;
            }
            ans = max(ans,head-tail+1);
        }
        
        return ans;
    }
};