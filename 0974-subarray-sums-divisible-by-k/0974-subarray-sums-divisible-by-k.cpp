class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int ans=0 , prefixsum=0;
        unordered_map<int,int>mp;
        mp[prefixsum]=1;
        for(auto it : nums)
        {
            prefixsum+=it;
            int rem = ((prefixsum%k)+k)%k;
            if(mp.find(rem)!=mp.end())
            {
                ans+=mp[rem];
                mp[rem]+=1;
            }
            else
                mp[rem]=1;
        }
        return ans;
    }
};