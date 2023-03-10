class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>hashset;
        for(auto it : nums){
            hashset.insert(it);
        }
        int longestStreak = 0;
        for(auto it : nums){
            if(!hashset.count(it-1)){
                int Currnumber = it;
                //length of the subsequence
                int CurrStreak  = 1;
                
                while(hashset.count(Currnumber + 1)){
                    Currnumber+=1;
                    CurrStreak+=1;
                }
                
                longestStreak = max(longestStreak,CurrStreak);

            }
            
        }
        return longestStreak;
    }
};